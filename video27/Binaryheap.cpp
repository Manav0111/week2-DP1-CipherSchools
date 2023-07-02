#include <vector>
using  namespace std;
class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
    	int ans=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        
        int parentindex=0;
        int leftchildindex=2*parentindex +1;
        int rightchildindex=2*parentindex +2;
        
        while(leftchildindex<pq.size())
        {
            int miniindex=parentindex;
            if(pq[leftchildindex]<pq[miniindex])
            {
                miniindex=leftchildindex;
            }
            
            if(rightchildindex<pq.size() && pq[rightchildindex]<pq[miniindex])
            {
                miniindex=rightchildindex;
            }
            if(miniindex==parentindex)
            {
                break;
            }
            int temp=pq[miniindex];
            pq[miniindex]=pq[parentindex];
            pq[parentindex]=temp;
            
            parentindex=miniindex;
        leftchildindex=2*parentindex +1;
         rightchildindex=2*parentindex +2;
        }        
       return ans; 
    }
};