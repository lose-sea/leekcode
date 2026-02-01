#include "raylib.h"
#include <math.h>

// 玫瑰曲线参数方程
Vector2 GetRosePoint(float angle, float k, float size, float time) {
    float r = cosf(k * angle) * size;
    float x = r * cosf(angle + time);
    float y = r * sinf(angle + time);
    return (Vector2){x, y};
}

// 获取渐变色
Color GetGradientColor(float t) {
    // 从红色到紫色渐变
    Color colors[] = {
        (Color){255, 0, 0, 255},     // 红色
        (Color){255, 105, 180, 255}, // 粉红
        (Color){138, 43, 226, 255},  // 蓝紫
        (Color){75, 0, 130, 255},    // 靛蓝
        (Color){0, 0, 255, 255}      // 蓝色
    };
    
    int numColors = 5;
    float segment = 1.0f / (numColors - 1);
    int index = (int)(t / segment);
    
    if (index >= numColors - 1) {
        return colors[numColors - 1];
    }
    
    float localT = (t - index * segment) / segment;
    Color c1 = colors[index];
    Color c2 = colors[index + 1];
    
    return (Color){
        (unsigned char)(c1.r + (c2.r - c1.r) * localT),
        (unsigned char)(c1.g + (c2.g - c1.g) * localT),
        (unsigned char)(c1.b + (c2.b - c1.b) * localT),
        255
    };
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 600;
    
    InitWindow(screenWidth, screenHeight, "彩色旋转玫瑰花 - C语言 Raylib");
    
    SetTargetFPS(60);
    
    float rotationSpeed = 0.5f;
    float time = 0.0f;
    
    // 玫瑰参数
    float k = 5.0f;      // 花瓣数量参数
    float size = 200.0f; // 玫瑰大小
    
    while (!WindowShouldClose()) {
        time += GetFrameTime() * rotationSpeed;
        
        BeginDrawing();
        
        // 渐变背景
        for (int i = 0; i < screenHeight; i++) {
            float t = (float)i / screenHeight;
            Color bgColor = (Color){
                (unsigned char)(10 + t * 20),
                (unsigned char)(10 + t * 10),
                (unsigned char)(30 + t * 40),
                255
            };
            DrawRectangle(0, i, screenWidth, 1, bgColor);
        }
        
        // 绘制标题
        DrawText("彩色旋转玫瑰花", 250, 20, 30, (Color){255, 255, 255, 255});
        DrawText("使用C语言 + Raylib绘制", 240, 60, 20, (Color){200, 200, 200, 255});
        
        // 绘制玫瑰中心点
        Vector2 center = {screenWidth / 2.0f, screenHeight / 2.0f};
        
        // 绘制旋转的玫瑰
        int segments = 1000;
        float angleStep = 2.0f * PI / segments;
        
        for (int i = 0; i < segments; i++) {
            float angle = i * angleStep;
            Vector2 point = GetRosePoint(angle, k, size, time);
            
            // 计算颜色
            float colorT = fmodf(angle / (2 * PI) + time * 0.1f, 1.0f);
            Color pointColor = GetGradientColor(colorT);
            
            // 绘制点
            DrawPixel(center.x + point.x, center.y + point.y, pointColor);
            
            // 绘制更大的点使图像更清晰
            if (i % 3 == 0) {
                DrawCircle(center.x + point.x, center.y + point.y, 1.5f, pointColor);
            }
        }
        
        // 绘制花心
        DrawCircle(center.x, center.y, 10, (Color){255, 255, 0, 255});
        DrawCircle(center.x, center.y, 5, (Color){255, 200, 0, 255});
        
        // 显示信息
        DrawFPS(10, 10);
        DrawText(TextFormat("时间: %.2f", time), 10, 40, 20, GREEN);
        DrawText("按ESC退出", 10, screenHeight - 30, 20, LIGHTGRAY);
        
        // 绘制控制说明
        DrawRectangle(10, screenHeight - 80, 200, 70, (Color){0, 0, 0, 180});
        DrawText("控制:", 15, screenHeight - 75, 20, YELLOW);
        DrawText("上/下: 调整速度", 15, screenHeight - 55, 15, WHITE);
        DrawText("R: 重置", 15, screenHeight - 40, 15, WHITE);
        
        EndDrawing();
        
        // 控制处理
        if (IsKeyPressed(KEY_UP)) rotationSpeed += 0.1f;
        if (IsKeyPressed(KEY_DOWN)) rotationSpeed = (rotationSpeed > 0.1f) ? rotationSpeed - 0.1f : 0.1f;
        if (IsKeyPressed(KEY_R)) {
            time = 0.0f;
            rotationSpeed = 0.5f;
        }
    }
    
    CloseWindow();
    return 0;
}