def is_balanced(s):
    stack = []
    pairs = {')': '(','}': '{', ']': '['}

    for ch in s:
        if ch in "({[":
            stack.append(ch)
        elif ch in ")}]":
            if not stack or stack[-1] != pairs[ch]:
                return False
            stack.pop()
    return len(stack) == 0

string = input("Enter a string of brackets: ")
if is_balanced(string):
    print("The brackets are balanced.") 
else:
    print("The brackets are not balanced.")