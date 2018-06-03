num_cases = STDIN.gets.chomp.to_i
current_case = 1
while line = STDIN.gets do 
	arr = line.chomp.split("").map {|a| a.to_i}
	num_digits = arr.count
	max_idx = num_digits - 1
	(1..max_idx).each do |n|
		idx = max_idx - n + 1
		break if arr[idx-1].nil? or arr[idx].nil?
		if arr[idx-1] > arr[idx]
			tmp = arr.join("").to_i - (arr[idx] + 1) * 10 ** (n - 1)
			arr = sprintf("%0#{num_digits}d", tmp).split("").map {|a| a.to_i}
			(idx..max_idx).each do |idx2|
				arr[idx2] = 9
			end
		end
	end
	puts "Case ##{current_case}: #{arr.join("").to_i}"
	current_case += 1
end
