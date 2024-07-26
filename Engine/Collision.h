#pragma once
//#include "Circle.h"
//
//#include "Circle.h"
//
//bool checkCollision(const Circle& circle1, const Circle& circle2) {
//    Vector2F diff = circle1.getPosition() - circle2.getPosition();
//    float distance = diff.length();
//    return distance < (circle1.getRadius() + circle2.getRadius());
//}
//
//void resolveCollision(Circle& circle1, Circle& circle2) {
//    Vector2F collisionNormal = (circle1.getPosition() - circle2.getPosition()).normalize();
//    Vector2F relativeVelocity = circle1.getVelocity() - circle2.getVelocity();
//    float velocityAlongNormal = relativeVelocity.dot(collisionNormal);
//
//    if (velocityAlongNormal > 0) {
//        return;
//    }
//
//    float e = 1.0f;  // Coefficient of restitution (elastic collision)
//    float j = -(1 + e) * velocityAlongNormal;
//    j /= 1 / circle1.getRadius() + 1 / circle2.getRadius();
//
//    Vector2F impulse = collisionNormal * j;
//    circle1.setVelocity(circle1.getVelocity() - impulse * (1 / circle1.getRadius()));
//    circle2.setVelocity(circle2.getVelocity() + impulse * (1 / circle2.getRadius()));
//}
//
