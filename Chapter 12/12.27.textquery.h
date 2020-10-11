//
// Created by KK on 2020/10/10.
//

#ifndef C___PRIMER_EXERCISE_12_27_TEXTQUERY_H
#define C___PRIMER_EXERCISE_12_27_TEXTQUERY_H

#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <memory>
#include <sstream>
#include <algorithm>

namespace Exercise1227 {

// 前置声明
    class TextQueryResult;

    class TextQuery {
        // 查询的结果是类的私有成员，TextQueryResult类需要获取查询的结果
        friend class TextQueryResult;

        using line_type = std::vector<std::string>;
        using dict_type = std::unordered_map<std::string, std::set<std::size_t>>;
        using keys_type = std::unordered_set<std::string>;
        using reuslt_type = std::pair<std::string, std::set<std::size_t>>;
        using obj_type = std::shared_ptr<TextQuery>;

    public:
        TextQuery() = default;;

        explicit TextQuery(std::string filePath) : file(std::move(filePath)) {
            readFile();
            combineResult(fileLines);
        }

        // 唯一的外部接口，用于接收需要查询的字符串
        obj_type query(const std::string &str);

    private:
        const std::string file;
        // 存储文件每一行的内容
        line_type fileLines;
        // 存储每个单词的映射表<单词,出现的行的集合>
        dict_type wordsTable;
        // 存储查询的结果pair<单词，出现的行的集合>
        reuslt_type queryResult;

        // 读取文件所有行
        void readFile();

        // 拆分一行的中所有单词，保存到集合中
        static keys_type splitLineContents(const std::string &lineString);

        // 生成每个单词的映射表
        void combineResult(const line_type &contents);

    };

    void TextQuery::readFile() {
        std::ifstream in_file(file);
        if (!in_file) {
            std::cout << file << " open fail." << std::endl;
            std::exit(-1);
        }
        std::string line;
        while (std::getline(in_file, line)) {
            fileLines.push_back(line);
        }
    }

    TextQuery::keys_type TextQuery::splitLineContents(const std::string &lineString) {
        std::istringstream stream(lineString);
        std::string word;
        keys_type word_keys;
        while (stream >> word) {

            word_keys.insert(word);
        }
        return word_keys;
    }

    void TextQuery::combineResult(const TextQuery::line_type &contents) {
        for (std::size_t i = 0; i < contents.size(); ++i) {
            const auto keys = splitLineContents(contents[i]);
            for (const auto &ck : keys) {
                wordsTable[ck].insert(i);
            }
        }
    }

    TextQuery::obj_type TextQuery::query(const std::string &str) {
        auto result = wordsTable.find(str);
        if (result != wordsTable.end()) {
            queryResult = *result;
        } else {
            // 没有找到时把查询的关键词记录一下，方便告知TextQueryResult是哪个关键词没有找到对应的行
            queryResult.first = str;
        }
        // 为了避免大量重复拷贝，TextQueryResult需要获取TextQuery的fileLines与queryResult
        // 通过shared_ptr实现TextQuery与TextQueryResult共享数据结果的目的
        return std::make_shared<TextQuery>(*this);
    }
}

#endif //C___PRIMER_EXERCISE_12_27_TEXTQUERY_H
