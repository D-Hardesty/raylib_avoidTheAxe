#include <iostream>
#include "raylib.h"

int main()
{

    int width{500};
    int height{300};
    InitWindow(width, height, "Hey");

//    circle attributes
    int circleX{250};
    int circleY{150};
    float radius{20.0f};
    int circleHitBoxYU;
    int circleHitBoxYD;
    int circleHitBoxXL;
    int circleHitBoxXR;

//    circle movement speed
    int circleMovement{5};


//    axe attributes
    int axeX{450};
    int axeY{0};
    int axeHeight{30};
    int axeWidth{30};
    int axeMod;
    int axeHitBoxYU;
    int axeHitBoxYD;
    int axeHitBoxXR;
    int axeHitBoxXL;

//    axe movement speed
    int axeMovementX{5};
    int axeMovementY{5};
    int axeSpeedMod{1};


    bool xCol{false};
    bool yCol{false};
    int timer{0};

    SetTargetFPS(60);

    // keep window open during gameplay
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        // region game logic

        if (xCol && yCol)
        {
            DrawText("Game Over!", 220, 120, 20, RED);
        } else
        {

            xCol = false;
            yCol = false;

            // region circle game logic
            DrawCircle(circleX, circleY, radius, RED);

            // move right
            if (IsKeyDown(KEY_D))
            {
                circleX += circleMovement;
            }
            // move left
            if (IsKeyDown(KEY_A))
            {
                circleX -= circleMovement;
            }
            // move up
            if (IsKeyDown(KEY_W))
            {
                circleY -= circleMovement;
            }
            // move down
            if (IsKeyDown(KEY_S))
            {
                circleY += circleMovement;
            }

            // region circle wrap
            if (circleX > 520)
            {
                circleX = 0;
            }
            if (circleX < int(-radius))
            {
                circleX = 520;
            }
            if (circleY > 320)
            {
                circleY = int(-radius);
            }
            if (circleY < int(-radius))
            {
                circleY = 320;
            }
            // endregion circle wrap



            // endregion circle game logic

            // endregion game logic ends

            // game logic
            DrawRectangle(axeX, axeY, axeWidth, axeHeight, WHITE);


            axeMod = GetRandomValue(-1, 1);
            // prevent axemod from zeroing out speed and maintaining randomness
            while (axeMod == 0)
            {
                axeMod = GetRandomValue(-1, 1);
            }

            if (axeY > 300)
            {
                axeX = GetRandomValue(0, 500);
                axeY = -axeHeight;
                axeMovementY *= axeMod;
            }
            if (axeY < -axeHeight)
            {
                axeX = GetRandomValue(0, 500);
                axeY = 300;
                axeMovementY *= axeMod;
            }
            if (axeX > 500)
            {
                axeY = GetRandomValue(0, 300);
                axeX = -axeHeight;
                axeMovementX *= axeMod;
            }
            if (axeX < -axeHeight)
            {
                axeY = GetRandomValue(0, 300);
                axeX = 500;
                axeMovementX *= axeMod;
            }


            axeX += axeMovementX;
            axeY += axeMovementY;

            timer += 1;

            // region speed up axe
            if (timer % 120 == 0)
            {
                if (axeMovementX < 0)
                {
                    axeMovementX -= axeSpeedMod;
                } else
                {
                    axeMovementX += axeSpeedMod;
                }
                if (axeMovementY < 0 && axeMovementX < 0 || axeMovementY > 0 && axeMovementX > 0)
                {
                    axeMovementY = axeMovementX;
                }
                if (axeMovementY > 0 && axeMovementX < 0 || axeMovementY < 0 && axeMovementX > 0)
                {
                    axeMovementY = axeMovementX * -1;
                }

            }
            // endregion speed up axe


            // calculate hitboxes
            // circle hitbox
            circleHitBoxXL = circleX - int(radius);
            circleHitBoxXR = circleX + int(radius);
            circleHitBoxYU = circleY - int(radius);
            circleHitBoxYD = circleY + int(radius);

            // axe hitbox
            axeHitBoxXL = axeX;
            axeHitBoxXR = axeX + axeWidth;
            axeHitBoxYU = axeY;
            axeHitBoxYD = axeY + axeHeight;


            // check collision X
            if (axeHitBoxXL <= circleHitBoxXR && axeHitBoxXR >= circleHitBoxXL)
            {
                xCol = true;
            }
            if (axeHitBoxYU <= circleHitBoxYD && axeHitBoxYD >= circleHitBoxYU)
            {
                yCol = true;
            }
            if (yCol && xCol)
            {
                std::cout << std::endl << "xCol: " << xCol << " yCol: " << yCol << std::endl;
                std::cout << circleHitBoxXL << ":X L circle R X:" << circleHitBoxXR << std::endl;
                std::cout << axeHitBoxXL << ":X L axe R X:" << axeHitBoxXR << std::endl;
                std::cout << circleHitBoxYU << ":Y U circle D Y:" << circleHitBoxYD << std::endl;
                std::cout << axeHitBoxYU << ":Y U axe D Y:" << axeHitBoxYD << std::endl << std::endl;
                std::cout << "You got hit" << std::endl;
                std::cout << "You lasted: " << timer / 60 << " seconds" << std::endl;
            }
        }

        std::cout << "timer:" << timer << std::endl;
        std::cout << "axeMovementX:" << axeMovementX << std::endl;
        std::cout << "axeMovementY:" << axeMovementY << std::endl;
        EndDrawing();

    }

    return 0;
}