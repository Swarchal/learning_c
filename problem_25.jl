function fib()
    fibos::Array{BigInt, 1} = [1, 1, 3]
    len, counter = 1, 3
    while len < 1000
        counter += 1
        next_num::BigInt = fibos[end] + fibos[end-1]
        len = length(string(next_num))
        push!(fibos, next_num)
    end
    println(counter)
end

fib()
