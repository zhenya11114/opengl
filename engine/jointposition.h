#pragma once

#include <engine/common.h>

class JointPosition{
public:
    glm::vec3 firstPos;
    glm::vec3 secondPos;

    glm::mat4 modelMatrix;

    glm::vec3 location;
    glm::vec3 rotation;
    glm::vec3 scale;

    glm::mat4 addTransform;

    JointPosition(){
        location = glm::vec3(0.f);
        rotation = glm::vec3 (0.f);
        scale = glm::vec3(1.f);
        modelMatrix = glm::mat4(1.f);
        addTransform = glm::mat4(1.f);
    }

    void updateMatrices(){
        modelMatrix = glm::mat4(1.f);
        modelMatrix = glm::translate(modelMatrix, location);

        glm::quat q(glm::radians(rotation));
        modelMatrix = glm::translate(modelMatrix, secondPos);
        modelMatrix = modelMatrix * glm::toMat4(q);
        modelMatrix = glm::translate(modelMatrix, -secondPos);
        modelMatrix = modelMatrix * addTransform;

        modelMatrix = glm::scale(modelMatrix, glm::vec3(scale));
    }

    glm::mat4 getModelMatrix(){
        return modelMatrix;
    }
    glm::mat4 getBoneModelMatrix(){
        return glm::translate(modelMatrix, secondPos);
    }
    void move(float x, float y, float z){
        location.x += x;
        location.y += y;
        location.z += z;
        updateMatrices();
    }
    void move(glm::vec3 location){
        this->location += location;
        updateMatrices();
    }
    void moveTo(float x, float y, float z){
        location.x = x;
        location.y = y;
        location.z = z;
        updateMatrices();
    }
    void moveTo(glm::vec3 location){
        this->location = location;
        updateMatrices();
    }
    void rotate(float x, float y, float z){
        rotation.x += x;
        rotation.y += y;
        rotation.z += z;
        updateMatrices();
    }
    void rotate(glm::vec3 rotation){
        this->rotation += rotation;
        updateMatrices();
    }
    void rotateTo(float x, float y, float z){
        rotation.x = x;
        rotation.y = y;
        rotation.z = z;
        updateMatrices();
    }
    void rotateTo(glm::vec3 rotation){
        this->rotation = rotation;
        updateMatrices();
    }
    void scaleTo(float x, float y, float z){
        scale.x = x;
        scale.y = y;
        scale.z = z;
        updateMatrices();
    }
    void scaleTo(glm::vec3 scale){
        this->scale = scale;
        updateMatrices();
    }
    glm::vec3 getLocation(){
        return location;
    }
    glm::vec3 getRotation(){
        return rotation;
    }
    glm::vec3 getScale(){
        return scale;
    }
};
