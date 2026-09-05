class Solution:
    def validParenthesesSubstring(self, s: str) -> bool:
        for paren in ("[]", "{}", "()"):
            for i in range(len(s) - 1):
                if s[i] == paren[0] and s[i + 1] == paren[1]:
                    return True
        return False
