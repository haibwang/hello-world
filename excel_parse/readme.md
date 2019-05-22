## 功能描述

+ 把特定格式的excel数据转换为c代码
  + 遍历excel内的所有注册表格，根据提供的模板，把每个表格数据生成一个结构体数据的C代码，每个sheet的名字作为数组名。

## 使用

+ 命令行进入应用所在目录，执行应用:`excel_parse.exe -h`可以查看帮助信息

+ 命令行参数定义：

  - -f：待解析excel文件名，目前只支持**xlsx**格式，不支持xls.
  - -t：模板名
  - -n：代码生成文件名，应用内部根据此名称匹配生成器，因此需根据需求选择
    - 选择列表
      + data_table.c

  例子：

  `%pwd%\excel_parse.exe -f a.xlsx -t data_table.tmpl -n data_table.c`