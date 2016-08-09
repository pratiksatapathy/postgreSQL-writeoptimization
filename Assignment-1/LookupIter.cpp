#include "LookupIter.h"
#include <iostream>
LookupIter::LookupIter(char *_key, KeyType _keyType, TreeNode *_node, int _position, int _payloadLen) {
    key = _key;
    keyType = _keyType;
    node = _node;
    position = _position;
    payloadlen = _payloadLen;
    nullIter = false;
}

LookupIter::LookupIter() {
    nullIter = true;
}

bool LookupIter::isNull() {
    return nullIter;
}

bool LookupIter::hasNext() {
    
   
        //std::cout<<"count "<<node->numkeys;
	char nodekey[keylen(&keyType)];
	int compareResult;
		node->getKey(keyType,nodekey,position+1);	
		
		 compareResult = compare(nodekey,key,keyType);
		 if(compareResult == 0)
		 return true;
		 else 
		 return false;

}

int LookupIter::next() {
  
     if(hasNext() == false) return -1;
     else {
	 position++; //increase position on next
	 return 0;
     }
}


int LookupIter::get(char *payload) {
    
     
     node->getPayload(payloadlen,payload,position);//pay load copied to variable payload
     if(hasNext()==false) return -1;
     else return 0;
}
