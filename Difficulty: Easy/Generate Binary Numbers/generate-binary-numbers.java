class Solution {
    public ArrayList<String> generateBinary(int n) {
        // code here
        ArrayList<String> res = new ArrayList<>();
        for(int i = 1 ; i <= n ; i++){
            String s = "";
            int temp = i;
            while(temp != 0) {
                s = (char)((temp%2)+'0') + s;
                temp /= 2;
            }
            res.add(s);
        }
        return res;
    }
}
