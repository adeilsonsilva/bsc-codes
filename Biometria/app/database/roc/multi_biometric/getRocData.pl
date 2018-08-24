#!/usr/bin/perl

use strict;
use warnings;

use constant {
	SAFES_TOTAL => 1250,
	NONSAFES_TOTAL => 61250
};

my %safes;
my %nonsafes;
my $limiar;
my $countVP;
my $countFP;
my $taxaVP;
my $taxaFP;


open(SAFES, '<', "safes");
open(NONSAFES, '<', "notSafes");
open(ROC, '>', "roc.txt");
open(LIMIAR, '>', "limiares.txt");

while(my $line = <SAFES>){
	chomp $line;
	$safes{$line}++;
	#push @safes, $line;
}
while(my $line = <NONSAFES>){
	chomp $line;
	$nonsafes{$line}++;
	#push @nonsafes, $line;
}

close(SAFES);
close(NONSAFES);

# loop do menor valor que o score atinge até o maior (0.0 -> 1.0)
# o threshold foi de 0.2 (dist < 0.2 == msm usuario)
# (e.g. duas imagens do msm usuário devem ter dist menores que de usuários diferentes)
for($limiar = 0.0; $limiar < 1.05; $limiar += 0.05){
	$countVP = 0;
	$countFP = 0;
	foreach my $valor (keys %safes){
		$countVP += $valor <= $limiar ? $safes{$valor} : 0;
		print "$valor $limiar $countVP\n";
	}

	foreach my $valor (keys %nonsafes){
		$countFP += $valor <= $limiar ? $nonsafes{$valor} : 0;
	}

	$taxaVP = $countVP/SAFES_TOTAL;
	$taxaFP = $countFP/NONSAFES_TOTAL;

	my $Out = sprintf("%.5f %.5f\n", $taxaFP, $taxaVP);
	print ROC $Out;
	$Out = sprintf("%.2f\n", $limiar);
	print LIMIAR $Out;
}
