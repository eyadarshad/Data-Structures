#include <emscripten/bind.h>
#include <string>
#include <vector>
#include <map>

using namespace emscripten;

// Simplified PageState structure
struct PageState {
    std::string pageId;
    std::map<std::string, std::string> formData;
    
    PageState() = default;
    PageState(const std::string& id) : pageId(id) {}
};

// Compact Stack Manager - combines both stacks
class StackManager {
private:
    std::vector<PageState> hStack; // History
    std::vector<PageState> rStack; // Redo
    PageState current;

public:
    StackManager(const std::string& initialPage) {
        current.pageId = initialPage;
    }

    // Forward navigation
    void forward(const std::string& targetPage) {
        hStack.push_back(current);
        rStack.clear();
        current = PageState(targetPage);
    }

    // Backward navigation
    bool back() {
        if (hStack.empty()) return false;
        
        rStack.push_back(current);
        current = hStack.back();
        hStack.pop_back();
        return true;
    }

    // Redo navigation
    bool redo() {
        if (rStack.empty()) return false;
        
        hStack.push_back(current);
        current = rStack.back();
        rStack.pop_back();
        return true;
    }

    // Getters
    std::string getCurrentPage() const { return current.pageId; }
    int getHistorySize() const { return hStack.size(); }
    int getRedoSize() const { return rStack.size(); }
    
    // Form data management
    void setFormData(const std::string& key, const std::string& value) {
        current.formData[key] = value;
    }
    
    std::string getFormData(const std::string& key) const {
        auto it = current.formData.find(key);
        return (it != current.formData.end()) ? it->second : "";
    }
    
    // Get all form data as JSON-like string
    std::string getAllFormData() const {
        std::string result = "{";
        bool first = true;
        for (const auto& pair : current.formData) {
            if (!first) result += ",";
            result += "\"" + pair.first + "\":\"" + pair.second + "\"";
            first = false;
        }
        result += "}";
        return result;
    }
};

// Emscripten bindings
EMSCRIPTEN_BINDINGS(stack_module) {
    class_<StackManager>("StackManager")
        .constructor<std::string>()
        .function("forward", &StackManager::forward)
        .function("back", &StackManager::back)
        .function("redo", &StackManager::redo)
        .function("getCurrentPage", &StackManager::getCurrentPage)
        .function("getHistorySize", &StackManager::getHistorySize)
        .function("getRedoSize", &StackManager::getRedoSize)
        .function("setFormData", &StackManager::setFormData)
        .function("getFormData", &StackManager::getFormData)
        .function("getAllFormData", &StackManager::getAllFormData);
}