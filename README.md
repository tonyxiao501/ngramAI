# ngramAI

## 项目简介
ngramAI 是一个基于 C++ 的 n-gram 模型实现，旨在处理和分析文本数据。该项目通过分词和文本生成等功能模块，能够高效地执行各种文本处理任务，适用于自然语言处理和数据分析应用。
### 分词 (Tokenization)
- **功能描述**：读取文本文件并将其分解为单词列表。
- **主要函数**：`doTokenizeFunction`
- **文件**：
  - `tokenize.h`
  - `tokenize.cpp`

### 文本生成 (Generation)
- **功能描述**：基于 n-gram 模型生成指定数量的单词，模拟自然语言文本。
- **主要函数**：`doGenerateFunction`
- **文件**：
  - `generate.h`
  - `generate.cpp`

### 实用函数 (Utilities)
- **功能描述**：提供辅助功能，如分词逻辑的实现等。
- **主要文件**：
  - `utils.h`
  - `utils.cpp`

## 使用说明
项目通过命令行参数控制不同的功能模块。以下是可用的参数：

- `--tokenize`：执行分词操作。
- `--generate`：执行文本生成功能。
- `--numWords <number>`：指定生成文本的单词数量（默认为100）。

**示例命令**：
```bash
ngramAI --tokenize --generate --numWords 50