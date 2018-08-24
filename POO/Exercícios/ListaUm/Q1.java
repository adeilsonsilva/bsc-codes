/*
 * Q1.java
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


public class automovel{
	
	private string combustivel;
	private string fabricante;
	private int ano_fabric;
	private string modelo;
	
	public automovel(String tipo_comb, String nome_fabr, int ano_fabric, string modelo){
		   combustivel = tipo_comb;
		   fabricante = fnome_fabr;
		   ano_fabric = ano_fabri;
		   modelo = modelo;
	}
	
	public CalculaCombustível(string comb, int percurso){
		
		int resultado;
		
		if(comb.equals("gasolina"){			
			resultado = percurso/12;			
		}
		
		if(comb.equals("alcool"){			
			resultado = percurso/15;			
		}
		
		if(comb.equals("flex"){			
			tmp1 = percurso/2;
			tmp2 = tmp1/12;
			tmp3 = tmp1/15;
			resultado = tmp2 + tmp3;			
		}
	}

}


