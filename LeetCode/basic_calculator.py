class Solution:
    def evaluate(self, ops: list):
        cur_result = 0
        while True:
            operand = ops.pop()
            if not bool(ops):
                cur_result += operand
                break
            operator = ops.pop()
            if operator == '(':
                cur_result += operand
                break
            if operator == '+':
                cur_result += operand
            elif operator == '-':
                cur_result -= operand
        # ops.append(cur_result)
        return cur_result

    def calculate(self, s: str) -> int:
        ops = []
        cur_num = 0
        for ch in s:
            if ch >= '0' and ch <= '9':
                cur_num = cur_num * 10 + int(ch)
            elif ch == '(' or ch == '+' or ch == '-':
                if ch != '(':
                    ops.append(cur_num)
                ops.append(ch)
                cur_num = 0
            elif ch == ')':
                ops.append(cur_num)
                cur_num = self.evaluate(ops)
        ops.append(cur_num)
        return self.evaluate(ops)
