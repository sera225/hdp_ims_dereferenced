<?php
	include('15_2_columns.inc');

	$link = $search . '/' . $page;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '<div class="pagination">') === false)
		$pageMax = 1;
	else if (strpos($html, '<span class="current">' . strval($page) . '</span><span class="disabled"> &#187;</span>') !== false)
		$pageMax = $page;

	$videos = explode('<li>', ($htmlToExplode = trim(str_between($html, '<ul class="video', '</ul>'))));
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
