num_cases = STDIN.gets.chomp.to_i
current_case = 1
while line = STDIN.gets do 
	pancakes_str, flipper_size = line.chomp.split(" ")
	flipper_size = flipper_size.to_i
	flip_count = 0

	left = 0
	target_range = Range.new(left, left + flipper_size - 1)
	while target_range.last < pancakes_str.length do
		if pancakes_str[left] == "-"
			flip_count += 1
			target_range.each do |i|
				pancakes_str[i] = pancakes_str[i] == "+" ? "-" : "+"
			end
		end
		left += 1
		target_range = Range.new(left, left + flipper_size - 1)
	end

	answer = if pancakes_str.include?("-")
		"IMPOSSIBLE"
	else
		flip_count
	end
	puts "Case ##{current_case}: #{answer}"
	current_case += 1
end
