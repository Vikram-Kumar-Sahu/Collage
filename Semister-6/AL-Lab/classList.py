s = Stack()

s.push(10)
s.push(20)
s.push(30)

print("Top:", s.peek())     # 30
print("Size:", s.size())    # 3

print("Popped:", s.pop())   # 30
print("New Top:", s.peek()) # 20

print("Is empty?", s.is_empty())  # False
