

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
       
        stack<pair<set<string>, set<string>>> stk;
        set<string> cur_union;
        set<string> cur_prod = {""};

        for (int i = 0; i < expression.length(); ++i) {
            char c = expression[i];
            
            if (isalpha(c)) {
                
                set<string> next_prod;
                for (const string& s : cur_prod) {
                    next_prod.insert(s + c);
                }
                cur_prod = move(next_prod);
                
            } else if (c == '{') {
                
                stk.push({cur_union, cur_prod});
                cur_union.clear();
                cur_prod = {""};
                
            } else if (c == '}') {
               
                for (const string& s : cur_prod) {
                    cur_union.insert(s);
                }
                
             
                auto [pre_union, pre_prod] = stk.top();
                stk.pop();
                
               
                set<string> next_prod;
                for (const string& p : pre_prod) {
                    for (const string& u : cur_union) {
                        next_prod.insert(p + u);
                    }
                }
                
                cur_prod = move(next_prod);
                cur_union = move(pre_union);
                
            } else if (c == ',') {
               
                for (const string& s : cur_prod) {
                    cur_union.insert(s);
                }
                cur_prod = {""};
            }
        }

        
        for (const string& s : cur_prod) {
            cur_union.insert(s);
        }

        
        return vector<string>(cur_union.begin(), cur_union.end());
    }
};
