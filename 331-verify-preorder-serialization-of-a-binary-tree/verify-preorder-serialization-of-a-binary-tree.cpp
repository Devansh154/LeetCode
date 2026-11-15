class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slot = 1;
        stringstream ss(preorder);
        string token;

        while(getline(ss, token , ',')){
            if(slot == 0){
                return false;
            }
            slot--;
            if(token != "#"){
                slot += 2;
            }
        }
        return slot == 0;
    }
};