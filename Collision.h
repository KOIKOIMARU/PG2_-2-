#pragma once
#include <math.h>

// 円同士の当たり判定（衝突判定）
inline bool CheckCircleCollision(int x1, int y1, int r1, int x2, int y2, int r2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int distanceSquared = dx * dx + dy * dy;
    int radiusSum = r1 + r2;
    return distanceSquared <= radiusSum * radiusSum;
}