def hoge(n)
	if n % 2 == 0
		(n - 1) / 2, (n - 1) / 2 + 1
	else
		(n - 1) / 2, (n - 1) / 2
	end
end

num_cases = STDIN.gets.chomp.to_i
current_case = 1
while line = STDIN.gets do 
	n, k = line.split(" ").map {|a| a.to_i}

	puts "Case #{current_case}: "
	current_case += 1
end
