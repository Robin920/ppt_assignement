#include<bits/stdc++.h>
using namespace std;

class Compare{
      public:
      bool operator()(const pair<int, string>& a, const pair<int, string>& b){
        if(a.first == b.first){
          return a.second > b.second;
        }
        return a.first < b.first;
      }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
      unordered_map<string, int> freq;
      priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
      for (auto str: words){
        freq[str]++;
      }
      for (auto i: freq){
        pq.push(make_pair(i.second, i.first));
      }
      words.clear();
      while (k--){
        words.push_back(pq.top().second);
        pq.pop();
      }
      return words;
    }
    
    int main(){
    	vector<string> words ={"i","love","leetcode","i","love","coding"};
    	int k = 2;
    	vector<string> ans = topKFrequent(words,k);
    	cout<<"Output: [";
    	for(auto it:ans){
    		cout<<it<<" , ";
		}
		cout<<"]";
    	return 0;
	}