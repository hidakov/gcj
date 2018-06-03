num_cases = STDIN.gets.chomp.to_i
current_case = 1
num_cases.times do 
	num_rows, num_cols = STDIN.gets.chomp.split(" ").map{|a| a.to_i}
	cake = Array.new
	done = Array.new
	num_rows.times do |i|
		cake[i] = STDIN.gets.chomp.split("")
		done[i] = [false] * num_cols
	end

	for i in 0..(num_rows-1)
		for j in 0..(num_cols-1)
			next if done[i][j]
			char = cake[i][j]
			next if char == "?"
			left_boundary = right_boundary = j
			#left
			(j-1).downto(0).each do |k|
				break if k < 0
				if cake[i][k] == "?"
					cake[i][k] = char
					done[i][k] = true
					left_boundary = k
				else
					break
				end
			end
			#right
			(j+1).upto(num_cols-1).each do |k|
				break if k >= num_cols
				if cake[i][k] == "?"
					cake[i][k] = char
					done[i][k] = true
					right_boundary = k
				else
					break
				end
			end
			#up
			(i-1).downto(0).each do |k|
				break if k < 0
				if cake[k][left_boundary..right_boundary].count{|a| a != "?"} == 0
					cake[k][left_boundary..right_boundary] = [char] * (right_boundary - left_boundary + 1)
					done[k][left_boundary..right_boundary] = [true] * (right_boundary - left_boundary + 1)
				else
					break
				end
			end
			#down
			(i+1).upto(num_rows-1).each do |k|
				break if k >= num_rows
				if cake[k][left_boundary..right_boundary].count{|a| a != "?"} == 0
					cake[k][left_boundary..right_boundary] = [char] * (right_boundary - left_boundary + 1)
					done[k][left_boundary..right_boundary] = [true] * (right_boundary - left_boundary + 1)
				else
					break
				end
			end
			done[i][j] = true
		end
	end

	puts "Case ##{current_case}:"
	cake.each do |row|
		puts row.join("")
	end
	current_case += 1
end
