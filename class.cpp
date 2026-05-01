#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;
//---------------------------------------------------------------------Player
struct Point {
    int x = 0;
    int y = 0;
};

class Player {
    public :
        int rollDice(int sides){
            /* Requirement:
               1. ใช้ rand() เพื่อสุ่มเลขระหว่าง 1 ถึง sides
               2. คืนค่าผลลัพธ์การทอยเพื่อนำไปใช้ในฟังก์ชัน move
            */
            srand(time(0)); 
            int random_num = rand();
            int Result = random_num % (sides + 1);
            return Result;
        }
        bool move(string direction){
            /* Requirement:
               1. ตรวจสอบ canMove ว่าติด Effect ห้ามเดินหรือไม่
               2. อัปเดตค่า x หรือ y ใน Point position ตามทิศทาง (W,A,S,D)
               3. ตรวจสอบขอบกระดาน (0-9) ไม่ให้เดินทะลุออกไป
               4. คืนค่า true หากเดินสำเร็จ
            */
            if(canMove) return false;
            
            //----------------------Split sting
            string split_direction;
            vector<string> direction_list;
        
            stringstream ss(direction);
            
            while(ss >> split_direction){
                direction_list.push(split_direction);
            }
            //----------------------Update position
            for(auto &i : direction_list){
                if((i != "W") || i != "A") || i != "S") || i != "D")) {
                    cout << "Invalid Move";
                    return false
                }
            }
            
            Point point;
            for(auto &i : direction_list){
                if((i == "A") || (i == "D")){
                    //update X
                    if((point.x > 0) || (point.x < 10)){
                        if(I == "A") point.x -= 1;
                        if(I == "D") point.x += 1;
                    }
                }
                if((i == "W") || (i == "S")){
                    //update Y
                    if((point.y > 0) || (point.y < 10)){
                        if(I == "W") point.y -= 1;
                        if(I == "S") point.y += 1;
                    }
                }
            }
            return true;
        }
        bool takeDamage(int amount){
            /* Requirement:
               1. ลดค่า hp ตาม amount ที่ได้รับ
               2. ถ้า hp <= 0 ให้ตั้งค่า isAlive = false และ hp = 0
               3. คืนค่า true ถ้าผู้เล่นยังไม่ตาย
            */
            return false;
        }
        bool heal(int amount){
            /* Requirement:
               1. เพิ่มค่า hp ตาม amount แต่ไม่เกินค่า MaxHP (เช่น 100)
               2. คืนค่า true หากการ Heal สำเร็จ
            */
            return false;
        }
    private :
        string name;
        int hp;
        Point position;
        bool isPoison;
        bool isAlive;
        int poisionTurnCount;
        bool canMove;
};

//---------------------------------------------------------------------Tile
class Tile{
    public:
        virtual ~Tile() {}
        virtual void triggerEffect(Player& player) = 0;
};

class NormalTile : public Tile {
    public : 
        void triggerEffect(Player& player) override{
            /* Requirement:
               - ไม่ส่งผลกระทบใดๆ ต่อผู้เล่น (อาจแสดงข้อความว่าปลอดภัย)
            */
        }
};

class WallTile : public Tile {
    public :
        void triggerEffect(Player& player) override{
            /* Requirement:
               - ขัดขวางการเดินหรือเด้งผู้เล่นกลับไปตำแหน่งเดิม
            */
        }
};

class TrapTile : public Tile {
    public :
        void triggerEffect(Player& player) override{
            /* Requirement:
               1. เรียก player.takeDamage(10)
               2. ตั้งค่า isPoison = true และ poisonTurnCount = 3
            */
        }
};

class AntidoteTile : public Tile {
    public :
        void triggerEffect(Player& player) override{
            /* Requirement:
               - ตั้งค่า isPoison = false และ reset poisonTurnCount เป็น 0
            */
        }
};

class QuestionableTile : public Tile {
    public :
        void triggerEffect(Player& player) override{
            /* Requirement:
               1. สุ่มตัวเลขเพื่อเลือก CardEffect (เช่นสุ่ม 1-7)
               2. สร้าง Object ของ Card คลาสนั้นๆ และเรียก applyEffect(player)
            */
        }
};

//---------------------------------------------------------------------Cardeffect
class CardEffect {
    public :
        virtual ~CardEffect() {}
        virtual void applyEffect(Player& player) = 0;
};

// [กลุ่มการ์ดดี]
class IncreaseHp : public CardEffect{
    public :
        void applyEffect(Player& player) override{
            // Requirement: เพิ่ม HP ให้ผู้เล่นที่เหยียบ 10 หน่วย
        }
};

class PlayerBlocker : public CardEffect{
    public :
        void applyEffect(Player& player) override{
            // Requirement: ทำให้ผู้เล่น "คนอื่น" ติดสถานะ canMove = false จนกว่าจะทอยได้แต้มที่กำหนด
        }
};

// [กลุ่มการ์ดไม่ดี]
class ReduceHp : public CardEffect{
    public :
        void applyEffect(Player& player) override{
            // Requirement: ผู้เล่นที่เหยียบเสียเลือด 10 หน่วย
        }
};

class LifeSteal : public CardEffect{
    public :
        void applyEffect(Player& player) override{
            /* Requirement: 
               - ลดเลือดคนอื่นคนละ 2 หน่วย แล้วนำมารวมเพิ่มให้ตัวเอง
               - ถ้าคนโดนดูดเลือดเหลือ < 6 ให้คนนั้นแพ้ทันที
            */
        }
};

//---------------------------------------------------------------------Board
class Board{
    public:
        /* Requirement:
           1. Constructor: ใช้ Loop 2 ชั้นสร้าง Tile* ชนิดต่างๆ ลงใน grid 10x10
           2. Destructor: ลบ (delete) ทุก Pointer ใน grid เพื่อคืนค่า Memory
        */
    private : 
        vector<vector <Tile*>> grid;
};

//---------------------------------------------------------------------GameEngine
class GameEngine {
    public :
        void nextTurn(){
            /* Requirement:
               1. วน Loop เปลี่ยนคิวผู้เล่น (คัดคนตายออก)
               2. ถ้าติดพิษ (isPoison) ให้ลดเลือดตามจำนวนเทิร์นที่เหลือ
               3. เรียกใช้ฟังก์ชันทอยเต๋าและเดิน
            */
        }
        void randomGasZone(){
            /* Requirement:
               - สุ่มพิกัดบนกระดานเพื่อกำหนดพื้นที่อันตราย (Gas) ที่จะลดเลือดทุกเทิร์น
            */
        }
        void shrinkBoard(){
            /* Requirement:
               - เมื่อ turncount ถึงจุดที่กำหนด ให้เปลี่ยน Tile ขอบๆ เป็นช่องที่เดินไม่ได้หรือช่องพิษ
            */
        }
        void checkWinner(){
            /* Requirement:
               - ตรวจสอบจำนวนผู้เล่นที่เหลือ isAlive == true หากเหลือ 1 คน ให้ประกาศผู้ชนะ
            */
        }
    private :
        vector <Player> player_list;
        Board board;
        int turncount;
        int totalHealth;
};

int main() {
    // เริ่มต้นระบบสุ่ม และสร้างตัวแปร GameEngine เพื่อ Run เกม
    Player player1;
    bool x = player1.move("W A S D W W W");
    return 0;
}