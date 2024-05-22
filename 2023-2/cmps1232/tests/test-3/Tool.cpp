#include "tool.h"

Tool::Tool() = default;

Tool::Tool(int newRecord, const std::string newToolName, int newQuantity) {
    setRecord(newRecord);
    setToolName(newToolName);
    setQuantity(newQuantity);
}

void Tool::setRecord(int newRecord) {
    recordNum = newRecord;
}

int Tool::getRecord() const {
    return recordNum;
}

void Tool::setToolName(const std::string newToolName) {
    toolName = newToolName;
}

std::string Tool::getToolName() const {
    return toolName;
}

void Tool::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

int Tool::getQuantity() const {
    return quantity;
}