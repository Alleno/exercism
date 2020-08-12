from dataclasses import dataclass
from typing import Optional


class Zipper(object):
    def __init__(self, root: 'Node', focus: 'Node' = None) -> None:
        self.root = root
        self.focus = focus or root

    @staticmethod
    def from_tree(tree: dict) -> Zipper:
        return Zipper(Node.from_tree(tree))

    def value(self) -> int:
        return self.focus.value

    def set_value(self, value: int) -> Zipper:
        self.focus.value = value
        return self

    def left(self) -> Optional['Zipper']:
        new_focus = self.focus.left
        return Zipper(self.root, new_focus) if new_focus else None

    def set_left(self, tree: dict) -> 'Zipper':
        self.focus.left = Node.from_tree(tree)
        return self

    def right(self) -> Optional['Zipper']:
        new_focus = self.focus.right
        return Zipper(self.root, new_focus) if new_focus else None

    def set_right(self, tree: dict) -> 'Zipper':
        self.focus.right = Node.from_tree(tree)
        return Zipper(self.root, self.focus.right)

    def up(self) -> 'Zipper':
        return Zipper(self.root, self.focus.parent)

    def to_tree(self) -> dict:
        return self.root.to_tree()


@dataclass
class Node:
    value: int
    left: 'Node' = None
    right: 'Node' = None
    parent: 'Node' = None

    @staticmethod
    def from_tree(tree: dict, parent: 'Node' = None) -> Optional['Node']:
        if tree is None:
            return None

        node = Node(tree['value'], parent)
        node.left = Node.from_tree(tree['left'], node)
        node.right = Node.from_tree(tree['right'], node)
        return node

    def to_tree(self) -> dict:
        return {
            'value': self.value,
            'left': self.left.to_tree() if self.left else None,
            'right': self.right.to_tree() if self.right else None
        }