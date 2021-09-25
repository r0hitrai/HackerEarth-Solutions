# You are creating a vaccine to fight against a worldwide novel pandemic virus.
# A vaccine contains a weakened virus that is injected inside people to produce
# antibodies to let if fight against the virus. The study of interaction among
# RNA of various viruses is quite necessary for this. An RNA consists of four 
# types of molecules Guaine (G), Agenin (A), Cytosine (C), and Uracil (U).
# You are given the structures of RNA for the pandemic virus and several vaccine
# viruses in the form of strings containing characters G, A, C, U representing
# respective molecules. You know that if there is higher interaction between the
# pandemic virus and vaccine virus, then better the vaccine will be. You also 
# know that the only interaction between any two RNAs is a result of the 
# interaction between their Guanine (G) and Cytosine (C) molecules. Formally, if
# the strings for RNA structures are s1 and s2, then you must consder the 
# following points:
# - One molecule of Guanine (G) of s1 and one molecule of Cytosine (C) of s2 will
#   lead to one unit of interaction.
# - One molecule of Guanin (G) of s2 and one molecule of Cytosine (C) of s1 will
#   lead to one unit of interaction.
# - Any other pair of molecules do not add to any interactions.
# In this way, the total interaction between s1 and s2 is calculated as the sum
# of individual molecule pair interactions (as discussed above).
# You must find the best available vaccine.

# calculating number of G and C pairs
def pairs(firstRNA, secondRNA):
	# number of G molecules in firstRNA
	GNos = 0
	# counting total number of G molecules in firstRNA
	for molecule in firstRNA:
		# if molecule is G
		if molecule == 'G':
			# count it
			GNos += 1
	# number of C molecules in secondRNA
	CNos = 0
	# counting total number of C molecules in secondRNA
	for molecule in secondRNA:
		# if molecule is C
		if molecule == 'C':
			# count it
			CNos += 1
	# total number of G and C molecule pairs
	pairNos = GNos * CNos
	# returning number of pairs
	return pairNos

# main function
# number of best vaccine;
bestVaccineNo = 0
# getting number of vaccines
vaccineNos = int(input())
# getting virus RNA length
virusLength = int(input())
# getting virus RNA
virusRNA = input()
# number of maximum interaction
interactionMax = 0
# RNA length of max interaction
interactionMaxLength = 0
# for every vaccine
for i in range(vaccineNos):
	# getting vaccine RNA length
	vaccineLength = int(input())
	# getting vaccine RNA
	vaccineRNA = input()
	# number of pair from virusRNA to vaccineRNA
	virusPairNos = pairs(virusRNA, vaccineRNA)
	# number of pair from vaccineRNA to virusRNA
	vaccinePairNos = pairs(vaccineRNA, virusRNA)
	# number of interaction
	interactionNos = virusPairNos + vaccinePairNos
	# if interactionNos is more than or equal to interactionMax
	if interactionNos >= interactionMax:
		# if interactionNos is equal to interactionMax
		if interactionNos == interactionMax:
			# if interactionNos RNA length is less than interactionMax RNA length
			if vaccineLength > interactionMaxLength:
				# current vaccine is the best vaccine
				bestVaccineNo = i + 1
				# set current vaccine as maximum interaction
				interactionMax = interactionNos
				interactionMaxLength = vaccineLength
		# else
		else:
			# current vaccine is the best vaccine
			bestVaccineNo = i + 1
			# set current vaccine as maximum interaction
			interactionMax = interactionNos
			interactionMaxLength = vaccineLength
# printing number of best vaccine
print(bestVaccineNo)
