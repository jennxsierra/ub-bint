#ifndef BINT_TOOL_H
#define BINT_TOOL_H

#include <string>

class Tool {
public:
    Tool();
    Tool(int, const std::string, int);
    void setRecord(int);
    [[nodiscard]] int getRecord() const;
    void setToolName(const std::string);
    [[nodiscard]] std::string getToolName() const;
    void setQuantity(int);
    [[nodiscard]] int getQuantity() const;

private:
    int recordNum;
    std::string toolName;
    int quantity;
};

#endif //BINT_TOOL_H