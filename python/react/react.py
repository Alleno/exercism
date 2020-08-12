from collections import deque

class Cell:
    call_queue = deque()
    def __init__(self, value):
        self._value = value
        self._dependents = []
        self._callbacks = []
        
    @property
    def value(self):
        return self._value
    
    @value.setter
    def value(self, val):
        if self._value == val:
            return
        self._value = val
        # Normally you could do a recursive call, by just using a for loop like this:
        # for dependent in self._dependents:
        #     dependent.value = dependent.compute_function()
        # 
        # but this causes the last test case to fail because the dfs nature of recursion
        # causes recomputation of all dependent nodes all the way down. We need to invert the call order by 
        # using a queue and closures instead (rather than the call stack)
        # so we are doing a bfs starting from the first input

        while self.call_queue: # Need to empty the queue before adding to it, otherwise we inadvertently do dfs
            c = self.call_queue.popleft()
            c()
        for dependent in self._dependents:
            self.call_queue.append(dependent._value_setter_callback())

        if self.call_queue: # Need to trigger the call queue at least once, in case we are changing the value on an input
            c = self.call_queue.popleft()
            c()

        for callback in self._callbacks:
            callback(self._value)


class InputCell(Cell):
    def __init__(self, initial_value):
        super().__init__(initial_value)


class ComputeCell(Cell):
    def __init__(self, inputs, compute_function):
        self.inputs = inputs
        self._compute_function = compute_function
        for input in inputs:
            input._dependents.append(self)
        super().__init__(self.compute_function())


    def add_callback(self, callback):
        self._callbacks.append(callback)

    def remove_callback(self, callback):
        try:
            self._callbacks.remove(callback)
        except ValueError:
            pass

    def compute_function(self):
        return self._compute_function([inp.value for inp in self.inputs])

    def _value_setter_callback(self):
        def closure():
            self.value = self.compute_function()
        return closure
