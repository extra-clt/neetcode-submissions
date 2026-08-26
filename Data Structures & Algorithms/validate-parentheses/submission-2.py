class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        st.append(s[0])
        for i in range(1,len(s)):
            b = s[i]
            if not st: 
                st.append(b)
            else:
                a = st[-1]
                if ((a == '{' and b == '}') or (a == '[' and b == ']') or (a == '(' and b == ')')):
                    st.pop()
                else:
                    st.append(b)

        if st: return False
        return True
        