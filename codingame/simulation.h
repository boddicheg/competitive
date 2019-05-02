#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <cassert>

using namespace std;

struct Entity
{
    int entityType;
    int owner;
    int x;
    int y;
    int param1;
    int param2;
};

enum EntityType
{
    TypePlayer = 0,
    TypeBomb = 1,
    TypeItem = 2
};

int width = 13;
int height = 11;
int my_id = 1;
int px = 2;
int py = 1;
int ticks = 8;
int range = 3;

vector<Entity> entities;

bool OutOfRange( int ex, int ey )
{
    return ex < 0 || ex >= width || ey < 0 || ey >= height;
}

constexpr int dirDx[4] = { -1, 1, 0, 0 };
constexpr int dirDy[4] = { 0, 0, -1, 1 };

void SimulateBomb( const vector<string>& board, vector<vector<int>>& boards, int frames )
{
    map<int, Entity> bombs;
    vector<int> bombsPosition( width * height, -1 );
    for( size_t i = 0; i < entities.size(); ++i )
    {
        auto e = entities.at(i);
        if( e.entityType != TypeBomb)
        {
            continue;
        }
        bombs.insert( { i, e } );
        bombsPosition.at( e.x + e.y * width ) = i;
    }
    // Current bombs
    cerr << "Bombs count is " << bombs.size() << endl;

    for( int tick = 0; tick < frames; ++tick )
    {
        vector<int> &ex = boards.at( tick );
        while( true )
        {
            int steps = 0;
            for( auto itt = bombs.begin(); itt != bombs.end(); )
            {
                Entity &current = itt->second;
                if( current.param1 == tick + 1 )
                {
                    steps++;
                    ex.at( current.y * width + current.x ) ++;
                    // All direction
                    for( int direction = 0; direction < 4; ++direction )
                    {
                        for( int range = 1; range < current.param2; ++range )
                        {
                            int nx = current.x + dirDx[direction] * range;
                            int ny = current.y + dirDy[direction] * range;
                            if( OutOfRange( nx, ny) )
                            {
                                continue;
                            }
                            if( board.at(ny).at(nx) == '.' )
                            {
                                ex.at(ny * width + nx) ++;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    itt = bombs.erase( itt );
                }
                else
                {
                    ++itt;
                }
            }
            if( steps == 0 )
            {
                break;
            }
        }
    }
    // Output
    for( int i = 0; i < frames; ++i )
    {
        cerr << "Frame #" << i << endl;
        for( int y = 0; y < height; ++y )
        {
            for( int x = 0; x < width; ++x )
            {
                cerr << boards.at(i).at( y * width + x );
            }
            cerr << endl;
        }
        cerr << endl;
    }
}

int main()
{
    Entity fake;
    fake.entityType = TypeBomb;
    fake.owner = my_id;
    fake.param1 = ticks;
    fake.param2 = range;
    fake.x = px;
    fake.y = py;

    entities.push_back( fake );

    vector<string> board = {
        ".............",
        ".X.X.X.X.X.X.",
        ".............",
        ".X.X.X.X.X.X.",
        ".............",
        ".X.X.X.X.X.X.",
        ".............",
        ".X.X.X.X.X.X.",
        ".............",
        ".X.X.X.X.X.X.",
        ".............",
    };
    vector<vector<int>> boards( ticks, vector<int>( width * height, 0 ));
    SimulateBomb( board, boards, ticks );
}

#endif // SIMULATION_H
