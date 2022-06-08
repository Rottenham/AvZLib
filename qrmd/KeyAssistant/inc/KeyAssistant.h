/*
 * @字符编码: UTF-8
 * @作者: qrmd
 * @时间: 2022-06-07 18:05:34
 * @描述: 按键辅助操作类
 * @AvZ版本：220213
 */

#include "avz.h"
using namespace AvZ;
#include <vector>

class KeyAssistant {
private:
    KeyConnector key_connect_plus;
    const std::vector<float> game_speeds = {0.1, 0.2, 0.5, 1.0, 2.0, 5.0, 10.0};
    // 舞王僵尸状态
    bool is_maid_activated = false;

public:
    // *** In Queue
    // 启用
    void enable()
    {
        InsertOperation([=]() {
            ShowErrorNotInQueue("按键辅助已启用，快捷键说明：\n数字键：在光标处种植对应卡槽位置的植物\nC：铲除光标处的植物\nR：开关高级暂停\nA：减慢游戏运行速度\nD：加快游戏运行速度\nS：恢复游戏运行速度\nX：开关女仆秘籍");
            // 按键种植
            key_connect_plus.add('1', [=]() { CardNotInQueue(1, MouseRow(), MouseCol()); });
            key_connect_plus.add('2', [=]() { CardNotInQueue(2, MouseRow(), MouseCol()); });
            key_connect_plus.add('3', [=]() { CardNotInQueue(3, MouseRow(), MouseCol()); });
            key_connect_plus.add('4', [=]() { CardNotInQueue(4, MouseRow(), MouseCol()); });
            key_connect_plus.add('5', [=]() { CardNotInQueue(5, MouseRow(), MouseCol()); });
            key_connect_plus.add('6', [=]() { CardNotInQueue(6, MouseRow(), MouseCol()); });
            key_connect_plus.add('7', [=]() { CardNotInQueue(7, MouseRow(), MouseCol()); });
            key_connect_plus.add('8', [=]() { CardNotInQueue(8, MouseRow(), MouseCol()); });
            key_connect_plus.add('9', [=]() { CardNotInQueue(9, MouseRow(), MouseCol()); });
            key_connect_plus.add('0', [=]() { CardNotInQueue(10, MouseRow(), MouseCol()); });

            // 按键铲除（优先南瓜头）
            key_connect_plus.add('C', [=]() { ShovelNotInQueue(MouseRow(), MouseCol(), true); });

            // 按键高级暂停
            SetAdvancedPauseKey('R');

            // 按键控制游戏运行速度
            key_connect_plus.add('A', [=]() {
                int game_speed_gear = 7;
                float game_speed = 10.0 / GetPvzBase()->tickMs();
                for (int i = 0; i < game_speeds.size(); ++i) {
                    if (game_speed <= game_speeds[i]) {
                        game_speed_gear = i;
                        break;
                    }
                }
                if (game_speed_gear > 0) {
                    SetGameSpeed(game_speeds[game_speed_gear - 1]);
                }
            });
            key_connect_plus.add('D', [=]() {
                int game_speed_gear = 0;
                float game_speed = 10.0 / GetPvzBase()->tickMs();
                for (int i = game_speeds.size() - 1; i >= 0; --i) {
                    if (game_speed >= game_speeds[i]) {
                        game_speed_gear = i;
                        break;
                    }
                }
                if (game_speed_gear < game_speeds.size() - 1) {
                    SetGameSpeed(game_speeds[game_speed_gear + 1]);
                }
            });
            key_connect_plus.add('S', [=]() {
                SetGameSpeed(1.0);
            });

            // 按键控制女仆秘籍
            key_connect_plus.add('X', [=]() {
                if (is_maid_activated) {
                    MaidCheats::callPartner();
                } else {
                    MaidCheats::stop();
                }
                is_maid_activated = !is_maid_activated;
            });

            // 按键停用按键辅助
            key_connect_plus.add('Q', [=]() {
                disable();
            });
        });
    }
    // *** In Queue
    // 停用
    void disable()
    {
        InsertOperation([=]() {
            key_connect_plus.clear();
            SetGameSpeed(1.0);
            MaidCheats::stop();
        });
        ShowErrorNotInQueue("按键辅助已停用，将恢复游戏运行速度并停用女仆秘籍");
    }
} key_assistant;
