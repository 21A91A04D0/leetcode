class MyQueue:
    
    def __init__(self):
        self.l = []

    def push(self, x: int) -> None:
        self.l.append(x)

    def pop(self) -> int:
        return self.l.pop(0)

    def peek(self) -> int:
        if(self.l):return self.l[0]

    def empty(self) -> bool:
        if(self.l):return False;
        return True;
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()