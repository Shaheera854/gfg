class Solution {
    public static void rotateDeque(Deque<Integer> dq, int type, int k) {
        // code here
        if(type == 1){
            while(k != 0){
                int temp = dq.removeLast();
                dq.addFirst(temp);
                k--;
            }
        }
        else{
            while(k != 0){
                int temp = dq.removeFirst();
                dq.addLast(temp);
                k--;
            }
        }
    }
}