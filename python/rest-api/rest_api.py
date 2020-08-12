from functools import wraps
import json
from typing import Dict, Any

def serialize(f):
    @wraps(f)
    def wrapper(self, url, payload=None):
        if payload: payload = json.loads(payload)
        res=f(self, url, payload)
        return json.dumps(res)
    return wrapper

class RestAPI:
    def __init__(self, database=None):
        self.db = database
        self.post_switch = {
            '/add': self._add_user,
            '/iou': self._add_iou,
        }

    @serialize
    def get(self, url, payload=None):
        if not payload:
            return {'users': [u['name'] for u in self.db['users']]}
        if not isinstance(payload['users'], list):
            userset = set([payload['users']])
        else:
            userset = set(payload['users'])
        return {'users': [u for u in self.db['users'] if u['name'] in userset]}

    @serialize
    def post(self, url, payload=None):
        return self.post_switch[url](payload)

    def _add_user(self, payload):
        new_person = {"name": payload['user'], 
                        "owes": payload.get("owes", {}), 
                        "owed_by": payload.get("owed_by", {}), 
                        "balance": payload.get("balance", 0.0)}
        self.db['users'].append(new_person)
        return new_person
    
    def _add_iou(self, payload):
        amount = payload['amount']

        lender = next(u for u in self.db['users'] if u['name'] == payload['lender'])
        borrower = next(u for u in self.db['users'] if u['name'] == payload['borrower'])

        lender['owed_by'].setdefault(borrower['name'], 0.0)
        lender['owed_by'][borrower['name']] += amount
        lender['balance'] += amount
        
        borrower['owes'].setdefault(lender['name'], 0.0)
        borrower['owes'][lender['name']] += amount
        borrower['balance'] -= amount
        self._normalize_balance(borrower, lender['name'])
        self._normalize_balance(lender, borrower['name'])

        return {'users': sorted([lender, borrower], key=lambda x: x['name'])}

    def _normalize_balance(self, user: Dict[str, Any], other: str) -> None:
        if other not in user['owed_by'] or other not in user['owes']:
            return

        if user['owed_by'][other] == user['owes'][other]:
            del user['owed_by'][other]
            del user['owes'][other]
        
        elif user['owed_by'][other] > user['owes'][other]:
            user['owed_by'][other] -= user['owes'][other]
            del user['owes'][other]
        
        else:
            user['owes'][other] -= user['owed_by'][other]
            del user['owed_by'][other]
