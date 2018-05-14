// https://www.codingame.com/ide/puzzle/don't-panic-episode-1

#ifndef DONTPANIC_H
#define DONTPANIC_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

enum class EState
{
    Nothing,
    Elevator,
    Exit,
    BlockedClone,
    NeedToBlock
};

const std::string BLOCK = "BLOCK";
const std::string WAIT = "WAIT";

typedef std::pair<int, int> Position;

class Game
{
public:
    void SetGameBoard(int floors, int w)
    {
        for(int i = 0; i < floors; ++i)
        {
            std::vector<EState> v(w, EState::Nothing);
            m_board.push_back(v);
        }
    }

    void SetExit(int exitFloor, int exitPos)
    {
        m_board.at(exitFloor).at(exitPos) = EState::Exit;
    }

    void SetElevator(int elevatorFloor, int elevatorPos)
    {
        m_board.at(elevatorFloor).at(elevatorPos) = EState::Elevator;
    }

    void PrintGameBoard() const
    {
        for(const auto& floor: m_board)
        {
            for(const auto& cell: floor)
            {
                switch (cell) {
                case EState::Nothing:
                    std::cerr << ".";
                    break;
                case EState::Exit:
                    std::cerr << "O";
                    break;
                case EState::BlockedClone:
                    std::cerr << "B";
                    break;
                case EState::Elevator:
                    std::cerr << "E";
                    break;
                case EState::NeedToBlock:
                    std::cerr << "?";
                    break;
                default:
                    break;
                }
            }
            std::cerr << std::endl;
        }
    }

    bool NeedToBlockClone(int cloneFloor, int clonePos, const std::string& direction)
    {
        // @TODO: Find on floor already blocked clone
        // Or calculate block position if there are no blocked clones on floor
        // Or simply WAIT
        if(m_board.at(cloneFloor).at(clonePos) == EState::NeedToBlock)
        {
            return true;
        }

        bool noBlockedClone = true;
        for(size_t i = 0; i < m_board.at(cloneFloor).size(); ++i)
        {
            EState cell = m_board.at(cloneFloor).at(i);
            if(cell == EState::BlockedClone || cell == EState::NeedToBlock)
            {
                noBlockedClone = false;
                break;
            }
        }

        if(noBlockedClone)
        {
            size_t positionForBlock = (direction == "LEFT") ? clonePos - 1 : clonePos + 1;
            if(positionForBlock >= m_board.at(cloneFloor).size())
            {
                // instantly block in this position
                return true;
            }

            m_board.at(cloneFloor).at(positionForBlock) = EState::NeedToBlock;
            return false;
        }
        else
        {
            return false;
        }
    }

    bool IsDirectionRigth(int cloneFloor, int clonePos, std::string direction)
    {
        // Check if clone going to elevator/exit
        size_t checkpointPosition = -1;
        for(size_t i = 0; i < m_board.at(cloneFloor).size(); ++i)
        {
            EState cell = m_board.at(cloneFloor).at(i);
            if(cell == EState::Elevator || cell == EState::Exit)
            {
                checkpointPosition = i;
                break;
            }
        }
        if((clonePos > checkpointPosition && direction == "LEFT") || (clonePos < checkpointPosition && direction == "RIGHT"))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    std::string Action(int cloneFloor, int clonePos, std::string direction)
    {
        // First check if clone direction same that direction to elevator/exit
        // if not same, calculate position of blocking leading clone
        if(clonePos == -1 || cloneFloor == -1)
        {
            return WAIT;
        }

        if(IsDirectionRigth(cloneFloor, clonePos, direction))
        {
            std::cerr << "Direction right. WAIT" << std::endl;
            return WAIT;
        }
        else
        {
            return (NeedToBlockClone(cloneFloor, clonePos, direction) ? BLOCK : WAIT);
        }
    }

private:
    std::vector<std::vector<EState>> m_board;
};


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    Game game;
    std::cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; std::cin.ignore();
    game.SetGameBoard(nbFloors, width);
    game.SetExit(exitFloor, exitPos);
    for (int i = 0; i < nbElevators; i++)
    {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        std::cin >> elevatorFloor >> elevatorPos; std::cin.ignore();
        game.SetElevator(elevatorFloor, elevatorPos);
    }

    std::cerr << "Floors: " << nbFloors << std::endl
              << "Width: " << width << std::endl
              << "Rounds: " << nbRounds << std::endl
              << "Exit floor: " << exitFloor << std::endl
              << "Exit position: " << exitPos << std::endl
              << "Total clones: " << nbTotalClones << std::endl
              << "Elevators: " << nbElevators << std::endl;

    game.PrintGameBoard();
    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        std::string direction; // direction of the leading clone: LEFT or RIGHT
        std::cin >> cloneFloor >> clonePos >> direction; std::cin.ignore();


        std::cerr << "Clone floor: " << cloneFloor << std::endl
                  << "Clone pos: " << clonePos << std::endl
                  << "Direction: " << direction << std::endl;

        std::cout << game.Action(cloneFloor, clonePos, direction) << std::endl; // action: WAIT or BLOCK
        game.PrintGameBoard();
    }
}

#endif // DONTPANIC_H