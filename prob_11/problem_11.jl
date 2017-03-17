addprocs(3)
@everywhere begin

    function col_max(m, n)
        """max 'n' length product in array 'm'"""
        current_max = 0
        for i in 1:size(m, 2)
            col = m[:, i]
            for i in 1:length(col) - n-1
                window_prod = prod(col[i : i+n-1])
                if window_prod > current_max
                    current_max = window_prod
                end
            end
        end
        return current_max
    end


    """rows are just a sideways columns, rotate 90 degrees and use col_max"""
    row_max(m, n) = col_max(rotr90(m), n)

    """split long diagonal into all n-length arrays (sliding window)"""
    split_to_len(arr, n) = [arr[i:i+n-1] for i in 1:length(arr)-n-1]


    function get_all_diagonals(m, n)
        """get all diagonals in matrix 'm' of at least length 'n'"""
        n_row = LinAlg.checksquare(m)
        all_diagonals = []
        for i in (0-n_row + n) : n_row - n
            diags = split_to_len.([diag(m, i), diag(rotr90(m), i)], n)
            append!(all_diagonals, diags)
        end
        return all_diagonals
    end


    function diag_max(m, n)
        """max 'n' length diagonal product in array 'm'"""
        current_max = 0
        diagonals = get_all_diagonals(m, n)
        flat_diags = [i for j in diagonals for i in j]
        for arr in flat_diags
            product = prod(arr)
            if product > current_max
                current_max = product
            end
        end
        return current_max
    end

end


function main()
    const data = readdlm(ARGS[1], Int)
    length(ARGS) == 2 ? n = Int(ARGS[2]) : n = 4
    funcs = [col_max, row_max, diag_max]
    vals = fetch.([@spawn f(data, n) for f in funcs])
    println(Int(maximum(vals)))
end

main()
