# 2026 ICPC 成都区域赛

本地题面：`C:/Users/LDM/Downloads/ICPC-Chengdu-2026-final.pdf`，A–M 共 13 题。全程没有联网。

**完成状态：12 / 13。L 尚未得到完整解法。** 其余各题的思路、推导、正确性论证、复杂度和实现要点见 `solutions/`，独立 C++17 程序位于 `std/`。

## 从易到难的排序与分档

档位含义：T1 基础；T2 基本算法加一个关键观察；T3 多步推导或精细构造；T4 核心结构不直观；T5 多项高级技巧或较长证明；T6 综合难题。相邻名次可以因选手知识背景而变化。

| 顺序 | 题目 | 档位 | 主要难点 | 题解 | 标程 |
|---:|---|:---:|---|---|---|
| 1 | D · Duel of Wrath | T1 | 同比例伤害转成公共累计倍率，处理最后一次越界 | [D](solutions/D.md) | [D.cpp](std/D.cpp) |
| 2 | M · Minimum Records | T1 | 维护已覆盖上界与可用的最大上界，延迟确定记录位置 | [M](solutions/M.md) | [M.cpp](std/M.cpp) |
| 3 | K · Keep Your Distance | T2 | 二分答案；可行集合虽有空洞，转移只需要两个极值 | [K](solutions/K.md) | [K.cpp](std/K.cpp) |
| 4 | I · Invisible Edges | T2 | DFS 括号序列，仅编码左括号位置即可恢复森林 | [I](solutions/I.md) | [I.cpp](std/I.cpp) |
| 5 | C · Counting Arrays | T2 | 增量转成定大小子集和，预处理高斯二项式型状态 | [C](solutions/C.md) | [C.cpp](std/C.cpp) |
| 6 | A · Average of Averages | T3 | 精确二进制分数、跨中点计数、按长度复用递归形状 | [A](solutions/A.md) | [A.cpp](std/A.cpp) |
| 7 | H · Hidden Order | T3 | 利用三个值域和记录最大值，在严格比较预算内排序 | [H](solutions/H.md) | [H.cpp](std/H.cpp) |
| 8 | E · Enclose the Point | T3 | 严格包含与凸包三角化，单独处理对角线退化 | [E](solutions/E.md) | [E.cpp](std/E.cpp) |
| 9 | B · Bouncing Particles | T4 | 反射展开、三角波分段、直线交点的整数区间去重 | [B](solutions/B.md) | [B.cpp](std/B.cpp) |
| 10 | G · Graph Reconstruction | T4 | 从矩阵行和恢复度数信息，枚举少量全局歧义 | [G](solutions/G.md) | [G.cpp](std/G.cpp) |
| 11 | L · Long Slides | T5（暂定） | 固定障碍的前后影响使局部路径构造失效；完整结构未解决 | [研究记录](solutions/L.md) | **未完成** |
| 12 | J · Joint Relocation | T5 | Monge 分治、队伍选择的单调性、截断凸函数扫描与回滚 | [J](solutions/J.md) | [J.cpp](std/J.cpp) |
| 13 | F · First Word | T6 | 后缀结构计数、幂和生成函数、下降阶乘基转换的转置算法 | [F](solutions/F.md) | [F.cpp](std/F.cpp) |

建议训练顺序：先完成 T1–T2，再按表向下。H 和 I 应配合本地交互器或两阶段测试，不能把样例交互文本当作普通输入运行。

## 程序与运行方式

所有已完成题目均为一个源文件，包含所需的数据结构与 NTT 实现，不依赖外部算法库。一般编译方式：

```text
g++ -std=c++17 -O2 std/A.cpp -o A
```

- H 是交互题：输出查询后刷新，读取比较结果，查询数上界为 `2n-3`。
- I 是两阶段通信题：同一程序根据开头的 `cat` 或 `dog` 执行编码或解码；两阶段不能共享运行状态。
- 其余已完成题目使用普通标准输入、标准输出。

已完成程序全部通过本地编译；具体对拍、构造验证与规模测试见 [统一验证说明](../tests/README.md)。这些程序是独立推导的候选标程，尚无官方评测记录。
