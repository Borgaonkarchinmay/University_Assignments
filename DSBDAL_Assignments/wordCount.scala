object sample{
	def main(args: Array[String]) {
                var linesRDD = sc.textFile("input.txt") // read input file
                 var wordsRDD = linesRDD.flatMap(_.split(" ")) // split the words
                 var wordsKvRdd = wordsRDD.map(word => (word,1));   // map the words with the frequency
                var wordCounts = wordsKvRdd.reduceByKey(_+_) // calculate frequency of the word
                wordCounts.saveAsTextFile("output.txt") // write output to external files
                wordCounts.foreach(println) // print the word count line by line from external file
        }
}

// As I implemented -> Through spark-shell terminal

output.txt file is saved to hadoop fd -ls

// As per instructions

Then,

Open spark shell in terminal

Command to load scala program:   :load directory/program_name.scala

Command to execute scala program:   program_name.main(Array())