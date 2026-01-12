class Solution:
    def fib(self, n: int) -> int:
        terms: list[int] = [0, 1, 1]
        length: int = len(terms)
        if n < length:
            return terms[n]
        while (length <= n):
            terms.pop(0)
            terms.append(terms[0] + terms[1])
            length += 1
        return terms[2]