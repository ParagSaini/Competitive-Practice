string checkRed(vector<char> ar) {
//     int previd1 = -1; 
//     int previd2 = -1;
//     stack<int> s;
//     for(int i=0; i<ar.size(); i++) {
//         if(ar[i] == '(') {
//             s.push(i);
//         }
//         else if(ar[i] == ')') {
//             if(i-s.top() == 2) return 'Yes';
//             else if(previd1 == -1 && previd2 == -1) {
//                 previd1 = s.top();
//                 s.pop();
//                 previd2 = i;
//             }
//             else {
//                 if(previd1 - s.top() == 1 && (i-previd2 == 1)) {
//                     return 'Yes';
//                 }
//             }
//         }
//     }
//     return 'No';
// }