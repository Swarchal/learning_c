using Combinatorics

for (idx, perm) in enumerate(permutations(range(0, 10)))
     if idx == 1000000
        println(reduce(*, map(x -> string(x), perm)))
        break
    end
end
