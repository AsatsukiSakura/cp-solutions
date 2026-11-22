# 2026 ICPC 西安区域赛

本地题面：`C:/Users/LDM/Downloads/statements.pdf`。根据 PDF 首页，它是 2026 ICPC Asia Xi’an Regional Contest，A–M 共 13 题。全程没有联网。

**完成状态：12 / 13。K 尚未得到满足通信位数与时间限制的完整方案。** 其余各题的思路、推导、正确性论证、复杂度和实现要点见 `solutions/`，独立 C++17 程序位于 `std/`。

## 从易到难的排序与分档

档位与成都使用同一尺度：T1 基础；T2 基本算法加一个关键观察；T3 多步推导或精细构造；T4 核心结构不直观；T5 多项高级技巧或较长证明；T6 综合难题。排名考虑完整约束下的发现、证明和实现成本，不依据未提供的过题统计。

| 顺序 | 题目 | 档位 | 主要难点 | 题解 | 标程 |
|---:|---|:---:|---|---|---|
| 1 | M · Melodiniq | T1 | 同一音符四人同时结算，死亡状态不可被后续恢复清除 | [M](solutions/M.md) | [M.cpp](std/M.cpp) |
| 2 | C · Cryptarithm | T2 | 循环源串编辑 DP，用两圈松弛处理删除闭包 | [C](solutions/C.md) | [C.cpp](std/C.cpp) |
| 3 | H · Hydra | T3 | 固定永久等级后求临时升级量，扫描分段线性函数 | [H](solutions/H.md) | [H.cpp](std/H.cpp) |
| 4 | J · Journey | T3 | 圆周相邻点配对，DSU 保证最终恰好一个环 | [J](solutions/J.md) | [J.cpp](std/J.cpp) |
| 5 | G · Gungnir Fracture | T3 | 二进制树上的三参数状态，以及强于最优值的归纳命题 | [G](solutions/G.md) | [G.cpp](std/G.cpp) |
| 6 | F · False Amber | T4 | 极小极大交换、对手最优阈值策略、精确有理数断点 | [F](solutions/F.md) | [F.cpp](std/F.cpp) |
| 7 | L · Lucid Traveler | T4 | 删除连通性刻画仙人掌，免费查询与付费路径排序分开核算 | [L](solutions/L.md) | [L.cpp](std/L.cpp) |
| 8 | B · Break the Speakers | T5 | MEX 操作正规形、两个边界状态和换根，证明成本较高 | [B](solutions/B.md) | [B.cpp](std/B.cpp) |
| 9 | I · Incyde | T5 | 按质因子统计切口同余类，处理 2-adic 分布、Lucas 与 CRT | [I](solutions/I.md) | [I.cpp](std/I.cpp) |
| 10 | D · Don’t Fight The Music | T5 | 前后缀连续约束组成排列树，16 个边界状态构造 | [D](solutions/D.md) | [D.cpp](std/D.cpp) |
| 11 | A · And Revive The Melody | T6 | 排列树计数、容斥、重叠与分离两种结构、带重置的卷积 DP | [A](solutions/A.md) | [A.cpp](std/A.cpp) |
| 12 | E · Ether Strike | T6 | Hamming 球交集、线段树摊还、颜色合并与稀疏延迟映射 | [E](solutions/E.md) | [E.cpp](std/E.cpp) |
| 13 | K · Kikai No Tsubasa | T6（暂定） | 压缩可行标号证书；仍缺少位数有保证且可快速解码的结构 | [研究记录](solutions/K.md) | **未完成** |

A 与 D 描述同一组前后缀约束，建议先读 D 的结构，再读 A 的计数。D 的可行性由构造 DP 精确判断，不能使用 A 的模计数是否为零来代替。

## 程序与运行方式

所有已完成题目均为一个源文件，不依赖外部算法库。一般编译方式：

```text
g++ -std=c++17 -O2 std/A.cpp -o A
```

- E 的取和语义是模 `2^64`，使用 `uint64_t` 自然回绕；本地版本启用了 x86 的 POPCNT 编译目标。
- F 输出浮点期望，但最优断点比较及费用分子使用整数或 `__int128`。
- L 是交互题：程序主动查询并刷新输出，不能直接喂入样例交互记录。配套本地交互器检查边集、查询总数和付费总量。
- K 原题为两次独立运行的通信题，本目录暂时没有 K 的实现。

已完成程序全部通过本地编译；具体对拍、构造验证与规模测试见 [统一验证说明](../tests/README.md)。这些程序是独立推导的候选标程，尚无官方评测记录。
