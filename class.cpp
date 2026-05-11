
// #include <iostream>
// #include <vector>
// #include <string>
// #include <cstdlib>
// #include <ctime>
// #include <sstream>
// using namespace std;
// //---------------------------------------------------------------------Player
// struct Point {
//     int x = 0;
//     int y = 0;
// };
// class Player {
//     public :
//         bool GetAlive() const {
//             return isAlive;
//         }
//         Player(std::string name_) : name(name_) {}
//         int rollDice(int sides){
//             /* Requirement:
//                1. ใช้ rand() เพื่อสุ่มเลขระหว่าง 1 ถึง sides
//                2. คืนค่าผลลัพธ์การทอยเพื่อนำไปใช้ในฟังก์ชัน move
//             */
//             srand(time(0)); 
//             int random_num = rand();
//             int Result = random_num % (sides + 1);
//             return Result;
//         }
//         bool move(string direction){
//             /* Requirement:
//                1. ตรวจสอบ canMove ว่าติด Effect ห้ามเดินหรือไม่
//                2. อัปเดตค่า x หรือ y ใน Point position ตามทิศทาง (W,A,S,D)
//                3. ตรวจสอบขอบกระดาน (0-9) ไม่ให้เดินทะลุออกไป
//                4. คืนค่า true หากเดินสำเร็จ
//             */
//             if(canMove) return false;
            
//             //----------------------Split sting
//             string split_direction;
//             vector<string> direction_list;
        
//             stringstream ss(direction);
            
//             while(ss >> split_direction){
//                 direction_list.push_back(split_direction);
//             }
//             //----------------------Update position
//             for(auto &i : direction_list){
//                 if((i != "W") || (i != "A") || (i != "S") || (i != "D")) {
//                     cout << "Invalid Move";
//                     return false;
//                 }
//             }
            
//             Point point;
//             for(auto &i : direction_list){
//                 if((i == "A") || (i == "D")){
//                     //update X
//                     if((point.x > 0) || (point.x < 10)){
//                         if(i == "A") point.x -= 1;
//                         if(i == "D") point.x += 1;
//                     }
//                 }
//                 if((i == "W") || (i == "S")){
//                     //update Y
//                     if((point.y > 0) || (point.y < 10)){
//                         if(i == "W") point.y -= 1;
//                         if(i == "S") point.y += 1;
//                     }
//                 }
//             }
//             return true;
//         }
//         bool takeDamage(int amount){
//             /* Requirement:
                
//                1. ลดค่า hp ตาม amount ที่ได้รับ
//                2. ถ้า hp <= 0 ให้ตั้งค่า isAlive = false และ hp = 0
//                3. คืนค่า true ถ้าผู้เล่นยังไม่ตาย
//             */
//            hp -= amount;
//              if( hp <= 0) {
//                 hp = 0;
//                 isAlive = false;
//                 return isAlive;
                
//             }
            
//             return isAlive;
//         }
//         bool heal(int amount){
//             /* Requirement:
//                1. เพิ่มค่า hp ตาม amount แต่ไม่เกินค่า MaxHP (เช่น 100)
//                2. คืนค่า true หากการ Heal สำเร็จ
//             */
//           hp += amount;
//         if (hp > 100) {
//         hp = 100;  // clamp ไม่ให้เกิน MaxHP
//         return true;}
//         }
//     private :
//         std::string name;
//         int hp = 100 ;
//         Point position;
//         bool isPoison = false;
//         bool isAlive = true;
//         int poisionTurnCount = 0;
//         bool canMove = true;
// };
// //---------------------------------------------------------------------Tile
// class Tile{
//     public:
//         virtual ~Tile() {}
//         virtual void triggerEffect(Player& player) = 0;
// };

// class NormalTile : public Tile {
//     public : 
//         void triggerEffect(Player& player) override{
//             /* Requirement:
//                - ไม่ส่งผลกระทบใดๆ ต่อผู้เล่น (อาจแสดงข้อความว่าปลอดภัย)
//             */
//         }
// };

// class WallTile : public Tile {
//     public :
//         void triggerEffect(Player& player) override{
//             /* Requirement:
//                - ขัดขวางการเดินหรือเด้งผู้เล่นกลับไปตำแหน่งเดิม
//             */
//         }
// };

// class TrapTile : public Tile {
//     public :
//         void triggerEffect(Player& player) override{
//             player.takeDamage(10);
            
       
//             player.heal(5);
//             /* Requirement:
//                1. เรียก player.takeDamage(10)
//                2. ตั้งค่า isPoison = true และ poisonTurnCount = 3
//             */
//         }
// };

// class AntidoteTile : public Tile {
//     public :
//         void triggerEffect(Player& player) override{
//             /* Requirement:
//                - ตั้งค่า isPoison = false และ reset poisonTurnCount เป็น 0
//             */
            
//         }
// };

// class QuestionableTile : public Tile {
//     public :
//         void triggerEffect(Player& player) override{
//             /* Requirement:
//                1. สุ่มตัวเลขเพื่อเลือก CardEffect (เช่นสุ่ม 1-7)
//                2. สร้าง Object ของ Card คลาสนั้นๆ และเรียก applyEffect(player)
//             */
//         }
// };

// //---------------------------------------------------------------------Cardeffect
// class CardEffect {
//     public :
//         virtual ~CardEffect() {}
//         virtual void applyEffect(Player& player) = 0;
// };

// // [กลุ่มการ์ดดี]
// class IncreaseHp : public CardEffect{
//     public :
//         void applyEffect(Player& player) override{
//             // Requirement: เพิ่ม HP ให้ผู้เล่นที่เหยียบ 10 หน่วย
//         }
// };

// class PlayerBlocker : public CardEffect{
//     public :
//         void applyEffect(Player& player) override{
//             // Requirement: ทำให้ผู้เล่น "คนอื่น" ติดสถานะ canMove = false จนกว่าจะทอยได้แต้มที่กำหนด
//         }
// };

// // [กลุ่มการ์ดไม่ดี]
// class ReduceHp : public CardEffect{
//     public :
//         void applyEffect(Player& player) override{
//             // Requirement: ผู้เล่นที่เหยียบเสียเลือด 10 หน่วย
            

//         }
// };

// class LifeSteal : public CardEffect{
//     public :
//         void applyEffect(Player& player) override{
//             /* Requirement: 
//                - ลดเลือดคนอื่นคนละ 2 หน่วย แล้วนำมารวมเพิ่มให้ตัวเอง
//                - ถ้าคนโดนดูดเลือดเหลือ < 6 ให้คนนั้นแพ้ทันที
//             */
//         }
// };

// //---------------------------------------------------------------------Board
// class Board{
//     public:
//         /* Requirement:
//            1. Constructor: ใช้ Loop 2 ชั้นสร้าง Tile* ชนิดต่างๆ ลงใน grid 10x10
//            2. Destructor: ลบ (delete) ทุก Pointer ใน grid เพื่อคืนค่า Memory
//         */
//     private : 
//         vector<vector <Tile*>> grid;
// };

// //---------------------------------------------------------------------GameEngine
// class GameEngine {
//     public :
//         void nextTurn(){
//             /* Requirement:
//                1. วน Loop เปลี่ยนคิวผู้เล่น (คัดคนตายออก)
//                2. ถ้าติดพิษ (isPoison) ให้ลดเลือดตามจำนวนเทิร์นที่เหลือ
//                3. เรียกใช้ฟังก์ชันทอยเต๋าและเดิน
//             */
          
//         }
//         void randomGasZone(){
//             /* Requirement:
//                - สุ่มพิกัดบนกระดานเพื่อกำหนดพื้นที่อันตราย (Gas) ที่จะลดเลือดทุกเทิร์น
//             */
//         }
//         void shrinkBoard(){
//             /* Requirement:
//                - เมื่อ turncount ถึงจุดที่กำหนด ให้เปลี่ยน Tile ขอบๆ เป็นช่องที่เดินไม่ได้หรือช่องพิษ
//             */
//         }
//         void checkWinner(){
//             /* Requirement:
//                - ตรวจสอบจำนวนผู้เล่นที่เหลือ isAlive == true หากเหลือ 1 คน ให้ประกาศผู้ชนะ
//                */
         
        
//    private :
//         vector <Player> player_list;
//         Board board;
//         int turncount;
//         int totalHealth;
//     };

// int main() {
//     // เริ่มต้นระบบสุ่ม และสร้างตัวแปร GameEngine เพื่อ Run เกม
//     Player player1("Boss");
//     Player player2("Potter");
//     Player player3("Pim");
//     Player player4("Nammon");
//     return 0;
// }


#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

//---------------------------------------------------------------------Point
struct Point {
    int x = 0;
    int y = 0;
};

//---------------------------------------------------------------------Player
class Player {
public:
    Player(string name_) : name(name_) {}

    bool   getIsAlive()         const { return isAlive; }
    bool   getIsPoison()        const { return isPoison; }
    int    getHp()              const { return hp; }
    bool   getCanMove()         const { return canMove; }
    int    getPoisonTurnCount() const { return poisionTurnCount; }
    Point  getPosition()        const { return position; }
    string getName()            const { return name; }
    int    getBlockDiceTarget() const { return blockDiceTarget; }

    void setIsPoison(bool v)       { isPoison = v; }
    void setPoisonTurnCount(int v) { poisionTurnCount = v; }
    void setCanMove(bool v)        { canMove = v; }
    void setBlockDiceTarget(int v) { blockDiceTarget = v; }
    void setPosition(Point p)      { position = p; }

    int rollDice(int sides) {
        return (rand() % sides) + 1;
    }

    bool move(string direction, int steps) {
        if (!canMove) {
            cout << name << " cannot move (Blocked)\n";
            return false;
        }
        if (direction != "W" && direction != "A" &&
            direction != "S" && direction != "D") {
            cout << "Invalid direction\n";
            return false;
        }
        for (int i = 0; i < steps; i++) {
            int nx = position.x;
            int ny = position.y;
            if      (direction == "A") nx -= 1;
            else if (direction == "D") nx += 1;
            else if (direction == "W") ny -= 1;
            else if (direction == "S") ny += 1;

            if (nx < 0 || nx > 9 || ny < 0 || ny > 9) {
                cout << name << " hit board edge, stopped at ("
                     << position.x << "," << position.y << ")\n";
                break;
            }
            position.x = nx;
            position.y = ny;
        }
        cout << name << " moved to (" << position.x << "," << position.y << ")\n";
        return true;
    }

    bool takeDamage(int amount) {
        hp -= amount;
        if (hp <= 0) {
            hp = 0;
            isAlive = false;
            cout << name << " HP is 0! Eliminated!\n";
            return false;
        }
        cout << name << " took damage " << amount << " | HP: " << hp << "\n";
        return true;
    }

    bool heal(int amount) {
        hp += amount;
        if (hp > 100) hp = 100;
        cout << name << " healed " << amount << " | HP: " << hp << "\n";
        return true;
    }

    void tickPoison() {
        if (!isPoison) return;
        takeDamage(2);
        poisionTurnCount--;
        if (poisionTurnCount <= 0) {
            isPoison = false;
            poisionTurnCount = 0;
            cout << name << " is cured of poison!\n";
        }
    }

    bool tryUnblock() {
        int roll = rollDice(20);
        cout << name << " rolled special dice: " << roll
             << " (need > " << blockDiceTarget << ")\n";
        if (roll > blockDiceTarget) {
            canMove = true;
            blockDiceTarget = 0;
            cout << name << " is unblocked!\n";
            return true;
        }
        return false;
    }

private:
    string name;
    int    hp               = 100;
    Point  position;
    bool   isPoison         = false;
    bool   isAlive          = true;
    int    poisionTurnCount = 0;
    bool   canMove          = true;
    int    blockDiceTarget  = 0;
};

//---------------------------------------------------------------------Tile
class Tile {
public:
    virtual ~Tile() {}
    virtual void triggerEffect(Player& player, vector<Player>& all_players) = 0;
    virtual bool isWalkable() const { return true; }
};

class NormalTile : public Tile {
public:
    void triggerEffect(Player& player, vector<Player>& all_players) override {
        cout << "Normal tile - safe\n";
    }
};

class WallTile : public Tile {
public:
    void triggerEffect(Player& player, vector<Player>& all_players) override {
        cout << "Wall! Cannot move here\n";
    }
    bool isWalkable() const override { return false; }
};

class TrapTile : public Tile {
public:
    void triggerEffect(Player& player, vector<Player>& all_players) override {
        cout << "Trap!\n";
        player.takeDamage(10);
        player.setIsPoison(true);
        player.setPoisonTurnCount(3);
        player.heal(5);
    }
};

class AntidoteTile : public Tile {
public:
    void triggerEffect(Player& player, vector<Player>& all_players) override {
        cout << "Antidote!\n";
        player.setIsPoison(false);
        player.setPoisonTurnCount(0);
        cout << player.getName() << " is cured of poison!\n";
    }
};

//---------------------------------------------------------------------CardEffect
class CardEffect {
public:
    virtual ~CardEffect() {}
    virtual void applyEffect(Player& player, vector<Player>& all_players) = 0;
};

class LifeStealGood : public CardEffect {
public:
    void applyEffect(Player& player, vector<Player>& all_players) override {
        cout << "[Card] Life Steal (Good)\n";
        int total = 0, count = 0;
        for (auto& other : all_players) {
            if (other.getName() == player.getName()) continue;
            if (!other.getIsAlive()) continue;
            total += 5;
            count++;
            other.takeDamage(5);
        }
        if (count > 0) player.heal(total / count);
    }
};

class IncreaseHp : public CardEffect {
public:
    void applyEffect(Player& player, vector<Player>& all_players) override {
        cout << "[Card] Increase HP 10\n";
        player.heal(10);
    }
};

class PoisonOthers : public CardEffect {
public:
    void applyEffect(Player& player, vector<Player>& all_players) override {
        cout << "[Card] Poison all others\n";
        for (auto& other : all_players) {
            if (other.getName() == player.getName()) continue;
            if (!other.getIsAlive()) continue;
            other.setIsPoison(true);
            other.setPoisonTurnCount(3);
            cout << other.getName() << " is poisoned!\n";
        }
    }
};

class BlockOthers : public CardEffect {
public:
    void applyEffect(Player& player, vector<Player>& all_players) override {
        cout << "[Card] Block all others\n";
        for (auto& other : all_players) {
            if (other.getName() == player.getName()) continue;
            if (!other.getIsAlive()) continue;
            other.setCanMove(false);
            other.setBlockDiceTarget(15);
            cout << other.getName() << " is blocked!\n";
        }
    }
};

class ReduceHp : public CardEffect {
public:
    void applyEffect(Player& player, vector<Player>& all_players) override {
        cout << "[Card] Reduce HP 10\n";
        player.takeDamage(10);
    }
};

class LifeStealBad : public CardEffect {
public:
    void applyEffect(Player& player, vector<Player>& all_players) override {
        cout << "[Card] Life Steal (Bad)\n";
        int drain = (int)(all_players.size() - 1) * 2;
        if (player.getHp() < 6)
            player.takeDamage(player.getHp());
        else
            player.takeDamage(drain);
        for (auto& other : all_players) {
            if (other.getName() == player.getName()) continue;
            if (!other.getIsAlive()) continue;
            other.heal(2);
        }
    }
};

class BlockSelf : public CardEffect {
public:
    void applyEffect(Player& player, vector<Player>& all_players) override {
        cout << "[Card] Block self\n";
        player.setCanMove(false);
        player.setBlockDiceTarget(15);
        cout << player.getName() << " is blocked!\n";
    }
};

class QuestionableTile : public Tile {
public:
    void triggerEffect(Player& player, vector<Player>& all_players) override {
        int roll = (rand() % 7) + 1;
        cout << "QUESTIONABLE TILE! Drew card #" << roll << "\n";
        CardEffect* card = nullptr;
        switch (roll) {
            case 1: card = new LifeStealGood(); break;
            case 2: card = new IncreaseHp();    break;
            case 3: card = new PoisonOthers();  break;
            case 4: card = new BlockOthers();   break;
            case 5: card = new ReduceHp();      break;
            case 6: card = new LifeStealBad();  break;
            case 7: card = new BlockSelf();     break;
        }
        if (card) { card->applyEffect(player, all_players); delete card; }
    }
};

//---------------------------------------------------------------------Board
class Board {
public:
    Board() {
        grid.resize(10, vector<Tile*>(10, nullptr));
        for (int y = 0; y < 10; y++)
            for (int x = 0; x < 10; x++)
                grid[y][x] = new NormalTile();
        setTile(2, 2, new TrapTile());
        setTile(5, 5, new AntidoteTile());
        setTile(7, 3, new QuestionableTile());
        setTile(1, 8, new WallTile());
    }
    ~Board() {
        for (auto& row : grid)
            for (auto* tile : row)
                delete tile;
    }
    Tile* getTile(int x, int y) const { return grid[y][x]; }
    void setTile(int x, int y, Tile* tile) { delete grid[y][x]; grid[y][x] = tile; }
    bool isWalkable(int x, int y) const {
        if (x < 0 || x > 9 || y < 0 || y > 9) return false;
        return grid[y][x]->isWalkable();
    }
    void shrink(int layer) {
        for (int i = layer; i < 10 - layer; i++) {
            setTile(layer,     i,         new WallTile());
            setTile(9 - layer, i,         new WallTile());
            setTile(i,         layer,     new WallTile());
            setTile(i,         9 - layer, new WallTile());
        }
        cout << "Board shrunk! Layer " << layer << " turned into walls\n";
    }
private:
    vector<vector<Tile*>> grid;
};

//---------------------------------------------------------------------GameEngine
class GameEngine {
public:
    GameEngine() : turncount(0), shrinkLayer(1), totalHealth(0), currentPlayer(0) {
        player_list.emplace_back("Boss");
        player_list.emplace_back("Potter");
        player_list.emplace_back("Pim");
        player_list.emplace_back("Nammon");
        currentPlayer = rand() % 4;
        cout << "First player: " << player_list[currentPlayer].getName() << "\n";
    }

    void nextTurn() {
        bool anyAlive = false;
        for (auto& p : player_list) if (p.getIsAlive()) anyAlive = true;
        if (!anyAlive) return;

        while (!player_list[currentPlayer].getIsAlive())
            currentPlayer = (currentPlayer + 1) % 4;

        Player& current = player_list[currentPlayer];
        cout << "\n=== Turn of " << current.getName()
             << " (HP: " << current.getHp() << ") ===\n";

        if (!current.getCanMove()) {
            if (!current.tryUnblock()) {
                cout << current.getName() << " still cannot move\n";
                endTurn();
                return;
            }
        }

        int steps = current.rollDice(6);
        cout << current.getName() << " rolled " << steps << "\n";

        string dirs[] = {"W", "A", "S", "D"};
        string dir = dirs[rand() % 4];
        cout << current.getName() << " moves direction " << dir << "\n";

        current.move(dir, steps);

        Point pos = current.getPosition();
        board.getTile(pos.x, pos.y)->triggerEffect(current, player_list);

        endTurn();
    }

    void endTurn() {
        turncount++;
        for (int i = 0; i < (int)player_list.size(); i++) {
            if (i == currentPlayer) continue;
            if (!player_list[i].getIsAlive()) continue;
            player_list[i].tickPoison();
        }
        totalHealth = 0;
        for (auto& p : player_list) if (p.getIsAlive()) totalHealth += p.getHp();
        cout << "Total HP: " << totalHealth << "\n";

        if (totalHealth < 200 && shrinkLayer < 5) shrinkBoard();

        int alivePlayers = 0;
        for (auto& p : player_list) if (p.getIsAlive()) alivePlayers++;
        if (alivePlayers > 0 && turncount % alivePlayers == 0) randomGasZone();

        checkWinner();
        currentPlayer = (currentPlayer + 1) % 4;
    }

    void randomGasZone() {
        if (rand() % 2 == 0) return;
        int originX = rand() % 8;
        int originY = rand() % 8;
        cout << "Gas Zone spawned at (" << originX << "," << originY
             << ") to (" << originX + 2 << "," << originY + 2 << ")\n";
        for (auto& p : player_list) {
            if (!p.getIsAlive()) continue;
            Point pos = p.getPosition();
            if (pos.x >= originX && pos.x <= originX + 2 &&
                pos.y >= originY && pos.y <= originY + 2) {
                cout << p.getName() << " is in the Gas Zone!\n";
                p.takeDamage(5);
            }
        }
    }

    void shrinkBoard() {
        cout << "Total HP below 200! Board shrinking\n";
        board.shrink(shrinkLayer);
        shrinkLayer++;
    }

    void checkWinner() {
        vector<Player*> alive;
        for (auto& p : player_list) if (p.getIsAlive()) alive.push_back(&p);

        if (alive.size() == 1) {
            cout << "\n*** " << alive[0]->getName() << " wins! ***\n";
            exit(0);
        }
        bool anyCanMove = false;
        for (auto* p : alive) if (p->getCanMove()) anyCanMove = true;

        if (!anyCanMove && alive.size() > 1) {
            Player* winner = alive[0];
            for (auto* p : alive)
                if (p->getHp() > winner->getHp()) winner = p;
            cout << "\n*** Board full! " << winner->getName()
                 << " has the most HP (" << winner->getHp() << ") - wins! ***\n";
            exit(0);
        }
    }

    void run(int maxTurns = 50) {
        for (int i = 0; i < maxTurns; i++) nextTurn();
        cout << "Game over (completed " << maxTurns << " turns)\n";
    }

private:
    vector<Player> player_list;
    Board          board;
    int            turncount;
    int            totalHealth;
    int            currentPlayer;
    int            shrinkLayer;
};

//---------------------------------------------------------------------main
int main() {
    srand(time(0));
    GameEngine engine;
    engine.run(50);
    return 0;
}