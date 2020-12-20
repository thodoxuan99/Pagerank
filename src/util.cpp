#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <math.h>

// Split the argument string, tokenize it with the argument deliminator, and
// store its tokens in the argument vector.
void Split(const std::string &s, const char *delim, std::vector<std::string> &v) {
    char *dup = strdup(s.c_str());
    char *token = strtok(dup, delim);
    while (token != NULL) {
        v.push_back(std::string(token));
        token = strtok(NULL, delim);
    }
    free(dup);
}

// Return true if there is still progress.
bool Progress(std::vector<double> v1, std::vector<double> v2, double thresh) {
    for (size_t i = 0; i < v1.size(); ++i) {
        if (fabs(v2.at(i) - v1.at(i)) > thresh) {
            return true;
        }
    }
    return false;
}