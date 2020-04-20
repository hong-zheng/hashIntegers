#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<map>
#include<stdlib.h> // memset	
#include<string.h> // malloc
#include<Windows.h>
#include<vector>
//#include<multimap>
using namespace std;

//进程：红黑二叉树（需要比较）
//不需要比较：哈希（衡量哈希优否就是看冲突概率）
// 用来保存3位的整数

struct node{
	int _data;
	node* pNext;
};
// 哈希表
struct HashTable{
	node**** pArray;
	//node* arr[10][10][10];
	//node** pArray;
	//vector<node> arr;
};
// 创建hash表
// 由于在main函数中定义的是*，因此现在需要改的是*,所以需要传的参数为**
void CreateHashTable(HashTable** pHash){
	*pHash = new HashTable;
	memset(*pHash,0,sizeof(HashTable));
}
// 初始化hashTable
void InitHashTable(HashTable* pHash){
	pHash->pArray = (node****)malloc(4 * 10);
	for (int i = 0; i < 10;i++){
		pHash->pArray[i] = (node***)malloc(4 * 10);
		for (int j = 0; j < 10;j++){
			pHash->pArray[i][j] = (node**)malloc(4 * 10);
			memset(pHash->pArray[i][j],0,40);
		}
	}
}
// 创建节点
node* createNode(int data){
	node* pNew = new node;
	pNew->_data = data;
	pNew->pNext = NULL;
	return pNew;
}
// 向hash表中添加数据
void insertNode2HashTable(HashTable* hash, int data){
	int bai_idx = data / 100;
	int shi_idx = data % 100 / 10;
	int ge_idx = data % 10;

	node* pNew = createNode(data);
	node* pTemp = NULL;
	if (hash->pArray[bai_idx][shi_idx][ge_idx]){
		pTemp = hash->pArray[bai_idx][shi_idx][ge_idx];
		while (pTemp->pNext){
			pTemp = pTemp->pNext;
		}
		pTemp->pNext = pNew;
	}
	else{
		hash->pArray[bai_idx][shi_idx][ge_idx] = pNew;
	}
}
// 查找返回地址 or NULL
node* findNode(HashTable* hash, int data){
	int bai_idx = data / 100;
	int shi_idx = data % 100 / 10;
	int ge_idx = data % 10;
	return hash->pArray[bai_idx][shi_idx][ge_idx];
}
int main(){
	HashTable* pHash = NULL;
	CreateHashTable(&pHash);
	InitHashTable(pHash);
	
	insertNode2HashTable(pHash, 0);
	insertNode2HashTable(pHash, 23);
	insertNode2HashTable(pHash, 12);
	insertNode2HashTable(pHash, 435);
	insertNode2HashTable(pHash, 56);
	insertNode2HashTable(pHash, 52);

	
	while (1);
	system("pause");
	return 0;
}