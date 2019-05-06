# HeldKarp
A very simple implementation of Held-Karp algorithm.

## Pseudocode <sub>[link](https://en.wikipedia.org/wiki/Held%E2%80%93Karp_algorithm#cite_note-5)</sub>
```
function algorithm TSP (G, n)
  for k := 2 to n do
    C({k}, k) := d1,k
  end for

  for s := 2 to n-1 do
    for all S ⊆ {2, . . . , n}, |S| = s do
      for all k ∈ S do
        C(S, k) := minm≠k,m∈S [C(S\{k}, m) + dm,k]
      end for
    end for
  end for

  opt := mink≠1 [C({2, 3, . . . , n}, k) + dk,1]
  return (opt)
end
```
