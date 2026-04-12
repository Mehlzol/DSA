// April 8, 2026 Assignment
// Cursor Based
// 4 inserts (first, last, pos, key)
// 4 deletes (first, last, pos, key)
// Queue for the Inventory

#include <stdio.h>
#include <string.h>

#define MAX 15
typedef char string[32];

typedef struct{
    string acctname;
    string id;
}User;    

typedef struct{
    string charName;
    float weight;
}Character;

typedef struct{
    int speed, acceleration, weight, handling, traction;
}Stats;

typedef struct{
    string name;
    Stats stats;
}Component;

typedef struct{
    Component car;
    Component wheels;
    Component glider;
    Stats total;
}Car;

typedef struct{
    string itemName;
    string desc;
}Inventory;

typedef struct{
    User IGN;
    Character selected;
    Car chosen;
    Inventory items[3];
    int coins;
}Player;

typedef struct{
    Player details;
    int next;
}cell, HeapSpace[MAX];

typedef struct{
    HeapSpace H;
    int avail;
}VHeap;

typedef struct{
    int L;
    int count;
}RaceList;

void initVHeap(VHeap *VH);
void initList(RaceList *RL);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int index);
void insertFirst(VHeap *VH, RaceList *RL, Player p);
void insertLast(VHeap *VH, RaceList *RL, Player p);
void insertAtPos(VHeap *VH, RaceList *RL, Player p, int pos);
void insertSorted(VHeap *VH, RaceList *RL, Player p);
void deleteFirst(VHeap *VH, RaceList *RL);
void deleteLast(VHeap *VH, RaceList *RL);
void deleteAtPos(VHeap *VH, RaceList *RL, int pos);
void deleteByKey(VHeap *VH, RaceList *RL, int coins);
void enqueue(VHeap *VH, Player p);
void dequeue(VHeap *VH);
void display(RaceList RL, VHeap VH);
Player createPlayer(char name[], int coins, Component car, Component wheels, Component glider);
Stats calculateTotalStats(Stats car, Stats wheels, Stats glider);

int main(){
    Component cars[10] = {
        {"Standard Kart", {3,3,3,3,3}},
        {"Speedster", {5,4,2,2,2}},
        {"Heavy Rider", {2,2,5,2,2}},
        {"Balanced Pro", {4,4,4,4,4}},
        {"Drift Master", {2,3,3,5,5}},
        {"Off-Roader", {3,2,4,3,5}},
        {"Light Runner", {4,5,1,4,3}},
        {"Grip King", {3,2,3,3,5}},
        {"Acceleration Build", {3,5,2,3,3}},
        {"Ultimate Setup", {5,5,5,5,5}},
    };
    
    Component wheels[10] = {
        {"Standard Wheels", {3,3,3,3,3}},
        {"Speed Wheels", {4,3,2,3,3}},
        {"Heavy Wheels", {2,2,4,2,2}},
        {"Balanced Wheels", {3,3,3,3,3}},
        {"Drift Wheels", {2,3,2,5,4}},
        {"Off-Road Wheels", {3,2,3,3,5}},
        {"Light Wheels", {3,4,1,4,3}},
        {"Grip Wheels", {3,2,3,3,5}},
        {"Acceleration Wheels", {2,4,2,3,3}},
        {"Premium Wheels", {5,5,5,5,5}},
    };
    
    Component gliders[10] = {
        {"Standard Glider", {3,3,3,3,3}},
        {"Speed Glider", {2,2,2,2,2}},
        {"Heavy Glider", {1,1,3,2,1}},
        {"Balanced Glider", {2,2,2,2,2}},
        {"Drift Glider", {1,2,2,4,3}},
        {"Off-Road Glider", {2,1,2,2,4}},
        {"Light Glider", {2,3,1,3,2}},
        {"Grip Glider", {2,1,2,2,4}},
        {"Acceleration Glider", {2,3,2,2,2}},
        {"Premium Glider", {5,5,5,5,5}},
    };
    
    VHeap VH;
    RaceList RL;

    initVHeap(&VH);
    initList(&RL);

    insertFirst(&VH, &RL, createPlayer("Mario", 50, cars[0], wheels[0], gliders[0]));
    insertLast(&VH, &RL, createPlayer("Luigi", 30, cars[1], wheels[1], gliders[1]));
    insertAtPos(&VH, &RL, createPlayer("Peach", 40, cars[2], wheels[2], gliders[2]), 1);
    insertSorted(&VH, &RL, createPlayer("Bowser", 60, cars[3], wheels[3], gliders[3]));
    display(RL, VH);

    deleteFirst(&VH, &RL);
    deleteLast(&VH, &RL);
    deleteAtPos(&VH, &RL, 1);
    deleteByKey(&VH, &RL, 40);

    printf("\nAfter Deletions:\n");
    display(RL, VH);

    return 0;
}

void initVHeap(VHeap *VH){
    int i;
    for(i = 0; i < MAX; i++){
        VH->H[i].next = i + 1;
    }
    VH->H[MAX-1].next = -1;
    VH->avail = 0;
}

void initList(RaceList *RL){
    RL->L = -1;
    RL->count = 0;
}

int allocSpace(VHeap *VH){
    int temp = VH->avail;
    if(temp != -1){
        VH->avail = VH->H[temp].next;
    }
    return temp;
}

void deallocSpace(VHeap *VH, int index){
    VH->H[index].next = VH->avail;
    VH->avail = index;
}

void insertFirst(VHeap *VH, RaceList *RL, Player p){
    int idx = allocSpace(VH);
    if(idx != -1){
        VH->H[idx].details = p;
        VH->H[idx].next = RL->L;
        RL->L = idx;
        RL->count++;
    }
}
void insertLast(VHeap *VH, RaceList *RL, Player p){
    int idx = allocSpace(VH);
    if(idx == -1) return;

    VH->H[idx].details = p;
    VH->H[idx].next = -1;

    if(RL->L == -1){
        RL->L = idx;
    } else {
        int trav = RL->L;
        while(VH->H[trav].next != -1){
            trav = VH->H[trav].next;
        }
        VH->H[trav].next = idx;
    }
    RL->count++;
}

void insertAtPos(VHeap *VH, RaceList *RL, Player p, int pos){
    if(pos == 0){
        insertFirst(VH, RL, p);
        return;
    }

    int idx = allocSpace(VH);
    if(idx == -1) return;

    int trav = RL->L;
    int i;
    for(i = 0; i < pos-1 && trav != -1; i++){
        trav = VH->H[trav].next;
    }

    if(trav != -1){
        VH->H[idx].details = p;
        VH->H[idx].next = VH->H[trav].next;
        VH->H[trav].next = idx;
        RL->count++;
    }
}

void insertSorted(VHeap *VH, RaceList *RL, Player p){
    int idx = allocSpace(VH);
    if(idx == -1) return;

    int *trav = &RL->L;

    while(*trav != -1 && VH->H[*trav].details.coins < p.coins){
        trav = &VH->H[*trav].next;
    }

    VH->H[idx].details = p;
    VH->H[idx].next = *trav;
    *trav = idx;
    RL->count++;
}

void deleteFirst(VHeap *VH, RaceList *RL){
    if(RL->L != -1){
        int temp = RL->L;
        RL->L = VH->H[temp].next;
        deallocSpace(VH, temp);
        RL->count--;
    }
}

void deleteLast(VHeap *VH, RaceList *RL){
    if(RL->L == -1) return;

    int *trav = &RL->L;

    while(VH->H[*trav].next != -1){
        trav = &VH->H[*trav].next;
    }

    int temp = *trav;
    *trav = -1;
    deallocSpace(VH, temp);
    RL->count--;
}

void deleteAtPos(VHeap *VH, RaceList *RL, int pos){
    if(pos == 0){
        deleteFirst(VH, RL);
        return;
    }

    int trav = RL->L;
    int i;

    for(i = 0; i < pos-1 && trav != -1; i++){
        trav = VH->H[trav].next;
    }

    if(trav != -1 && VH->H[trav].next != -1){
        int temp = VH->H[trav].next;
        VH->H[trav].next = VH->H[temp].next;
        deallocSpace(VH, temp);
        RL->count--;
    }
}

void deleteByKey(VHeap *VH, RaceList *RL, int coins){
    int *trav = &RL->L;

    while(*trav != -1 && VH->H[*trav].details.coins != coins){
        trav = &VH->H[*trav].next;
    }

    if(*trav != -1){
        int temp = *trav;
        *trav = VH->H[temp].next;
        deallocSpace(VH, temp);
        RL->count--;
    }
}

void enqueueItem(Player *p, Inventory item) {
    p->items[2] = p->items[1];
    p->items[1] = p->items[0];
    p->items[0] = item;
}

void dequeueItem(Player *p) {
    strcpy(p->items[2].itemName, "");
    strcpy(p->items[2].desc, "");

    p->items[2] = p->items[1];
    p->items[1] = p->items[0];

    strcpy(p->items[0].itemName, "");
    strcpy(p->items[0].desc, "");
}

void display(RaceList RL, VHeap VH) {
    int trav = RL.L;

    printf("\n=== PLAYER LIST ===\n");

    while (trav != -1) {
        Player p = VH.H[trav].details;

        printf("Name: %s | ID: %s | Coins: %d\n",
               p.IGN.acctname,
               p.IGN.id,
               p.coins);

        trav = VH.H[trav].next;
    }

    printf("====================\n");
}

Player createPlayer(char name[], int coins, Component car, Component wheels, Component glider){
    Player p;

    strcpy(p.IGN.acctname, name);
    strcpy(p.IGN.id, name); 
    p.coins = coins;
    p.chosen.car = car;
    p.chosen.wheels = wheels;
    p.chosen.glider = glider;
    p.chosen.total = calculateTotalStats(car.stats, wheels.stats, glider.stats);

    return p;
}

Stats calculateTotalStats(Stats car, Stats wheels, Stats glider){
    Stats total;
    total.speed = car.speed + wheels.speed + glider.speed;
    total.acceleration = car.acceleration + wheels.acceleration + glider.acceleration;
    total.weight = car.weight + wheels.weight + glider.weight;
    total.handling = car.handling + wheels.handling + glider.handling;
    total.traction = car.traction + wheels.traction + glider.traction;
    return total;
}