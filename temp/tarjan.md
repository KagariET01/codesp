先dfs所有的點  
每次dfs時，檢查有沒有回邊  
紀錄如果再走一條回邊，可以到達的最老祖先  
例如1->2->3->4->5  
目前還只是一棵樹  
現在新增兩條邊3->1 5->3  
很明顯的，那兩條邊對於剛剛的樹是回邊  
那我們在點3，我們繼續走下去，最老可以走回點1  
相對的，我們點5最老可以走到3  
而如果有任何子節點的low value>=自己的時間戳，代表該點達不到比自己高的地方，則這個點就是割點  
特例：根節點，且子樹大小<=1則不會是割點


