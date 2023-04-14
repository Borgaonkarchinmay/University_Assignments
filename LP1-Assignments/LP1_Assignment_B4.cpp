#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>

using namespace std;

class Virtual_Memory{
    int pageFrames;
    int pageFault;
    int* pframe;
public:
    Virtual_Memory();
    Virtual_Memory(int);
    int  get_pageFault(){return pageFault;}
    void LRU_pgRep(int*, int);
    void FIFO_pgRep(int*, int);
    void get_pframe();
    void alloc_frame_space();
    ~Virtual_Memory();
};

Virtual_Memory :: Virtual_Memory(){
    pageFrames = 0;
    pageFault = 0;
    pframe = nullptr;
}

Virtual_Memory :: Virtual_Memory(int pgFrames){
    pageFrames = pgFrames;
    pageFault = 0;
    int* pframe = nullptr;
    //for(int i = 0; i < pageFrames; i++){ pframe[i] = -1;}
}

Virtual_Memory :: ~Virtual_Memory(){
    delete []pframe;
}

void Virtual_Memory :: LRU_pgRep(int* inpStr, int len){
    
    auto cmp = [](pair<int, int> p1, pair<int, int> p2){
        return p1.second < p2.second; 
    };

    vector<pair<int, int>> pageTrack;
    pageFault = 0;
    int time_elapse = 1;
    alloc_frame_space();
    for(int i = 0; i < len; i++){
        bool present = false;
        
        for(int j = 0; j < pageFrames; j++){
            if((pframe[j] == inpStr[i])  || (pframe[j] == -1)) {
                if(pframe[j] == -1){
                    pframe[j] = inpStr[i];
                    pair<int, int> pr = {inpStr[i], time_elapse};
                    pageTrack.emplace_back(pr);
                    sort(pageTrack.begin(), pageTrack.end(), cmp);
                    pageFault++;
                }
                else{
                    for(auto pr : pageTrack){
                        if(pr.first == inpStr[i]){
                            pr.second = time_elapse;
                            sort(pageTrack.begin(), pageTrack.end(), cmp);
                            break;
                        }
                    }
                }
                present = true;
                break;
            }
        }

        if(!present){
            int pgNo = pageTrack[0].first;
            pageTrack.erase(pageTrack.begin());
            for(int j = 0; j < pageFrames; j++){
                if(pframe[j] == pgNo){ 
                    pframe[j] = inpStr[i]; 
                    pair<int, int> pr = {inpStr[i], time_elapse};
                    pageTrack.emplace_back(pr);
                    sort(pageTrack.begin(), pageTrack.end(), cmp);
                    pageFault++; 
                    break;
                }
            }  
        }
        //tracks time of
        time_elapse++;
        for(auto pr : pageTrack){cout<<pr.first<<", ";}
        cout<<endl;

    }
}

void Virtual_Memory :: alloc_frame_space(){
    pframe = new int[pageFrames];
    for(int i = 0; i < pageFrames; i++){ pframe[i] = -1;}
}

void Virtual_Memory :: FIFO_pgRep(int* inpStr, int len){
    queue<int> pgQueue;
    alloc_frame_space();
    pageFault = 0;

    for(int i = 0; i < len; i++){
        bool present = false;
        
        for(int j = 0; j < pageFrames; j++){
            //cout<<pframe[j]<<" ";
            if((pframe[j] == inpStr[i])  || (pframe[j] == -1)) {
                if(pframe[j] == -1){
                    pframe[j] = inpStr[i];
                    pgQueue.push(inpStr[i]);
                    pageFault++;
                }
                present = true;
                break;
            }
        }

        if(!present){
            int pgNo = pgQueue.front();
            for(int j = 0; j < pageFrames; j++){
                if(pframe[j] == pgNo){ pframe[j] = inpStr[i]; pgQueue.push(inpStr[i]); pageFault++; break;}
            }
            pgQueue.pop();  
        }
    }
}

void Virtual_Memory :: get_pframe(){
    cout<<pageFrames<<endl;
    for(int i = 0; i < pageFrames; i++){
        cout<<pframe[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int size = 0;
    int pageFrames = 0;
    cout<<"Enter no of pages in sequence: ";
    cin>>size;
    cout<<"Enter no of page frames in sequence: ";
    cin>>pageFrames;
    int arr[size];
    cout<<"Enter page reference string: ";
    for(int i = 0; i < size; i++) cin>>arr[i];

    Virtual_Memory p1(pageFrames);
    p1.LRU_pgRep(arr, size);
    int pgF = p1.get_pageFault();
    
    cout<<"Page fault by FIFO algorithm: "<<pgF<<endl;
    
    return 0;
}


