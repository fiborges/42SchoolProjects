<p align="center">
	<img src="https://github.com/fiborges/42SchoolProjects/blob/main/So_Long/20230311_113312.jpg" width="600" height="300"/>>
</p>

<h1 align="center">
	Description
</h1>
<p align="center">
	This is a 42 School's project. The project consists in creating a little 2D game with the MiniLibX, the school's graphic library.
</p>

<h2 align="center">
	The Game
</h2>
<p align="center">
	The purpose of the game is to obtain all collectibles (cookies) of the level.
</p>

<h2 align="center">
	Commands
</h2>
<table align="center">
	<tr>
		<td align="center"><code>W</code><br>Moving up</td>
		<td align="center"><code>A</code><br>Moving left</td>
		<td align="center"><code>S</code><br>Moving down</td>
		<td align="center"><code>D</code><br>Moving right</td>
		<td align="center"><code>ESC</code><br>Close the game</td>
	</tr>
</table>

<p align="center">
	A map set is provided in "maps" folder.
</p>

<h2 align="center">
	Map Composition
</h2>
<table align="center">
	<tr>
		<td>
			<h3 align="center">
				Valid Characters
			</h3>
			<table align="center">
				<tr>
					<td align="center">Character</td><td align="center">Element</td>
				</tr>
				<tr>
					<td align="center"><code>0</code></td><td align="center">Ground</td>
				</tr>
				<tr>
					<td align="center"><code>1</code></td><td align="center">Wall</td>
				</tr>
				<tr>
					<td align="center"><code>C</code></td><td align="center">Collectible</td>
				</tr>
				<tr>
					<td align="center"><code>E</code></td><td align="center">Exit</td>
				</tr>
				<tr>
					<td align="center"><code>P</code></td><td align="center">Starting Position</td>
				</tr>
				</tr>
			</table>
		</td>
		<td>
			<table align="center">
				<h3 align="center">
					Map Example
				</h3>
				<tr>
					<td><br><br>
						<pre align="center">
111111111
111000111
1PH0C00E1
1110M0111
111111111</pre><br><br>
						<p align="center">
							<i>Content .ber file</i>
						</p>
						</p>
					</td>
				</tr>
			</table>
		</td>
	</tr>
</table>

<p>
	To be valid, a map must meet the following conditions :
	<ul>
		<li>be rectangular</li>
		<li>surrounded by walls</li>
		<li>contain only one starting position</li>
		<li>contain only one exit door</li>
		<li>contain at least one collectible</li>
		<li>be composed by only valid characters</li>
		<li>the file contain map must be at .ber format</li>
	</ul>
</p>
