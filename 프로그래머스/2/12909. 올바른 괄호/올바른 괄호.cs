using System;
using System.Collections.Generic;

public class Solution 
{
    public bool solution(string s) 
    {
        bool answer = true;
        Stack<char> stk = new Stack<char>();
        foreach(var ch in s) {
            if(ch == ')') {
                if(stk.Count > 0 && stk.Peek() == '(') { stk.Pop(); }
                else { answer = false; break; }
            } else { stk.Push(ch); }
        }
        
        if(stk.Count > 0) { answer = false; }
        return answer;
    }
}