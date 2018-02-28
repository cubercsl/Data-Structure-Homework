#include "String.h"
int main()
{
    String s = "aabbabcbaabaaacbab";
    String t = "bab";
    String v = "abdc";
    s.Replace(t, v);
    Write(s);
}